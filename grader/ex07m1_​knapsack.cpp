#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

/*
test case:
10.0 4
1.2 3.4 6.3 1.3
4.2 1.4 6.7 4.3
output 9.7
*/

int n;
float cap, maxV;
vector<float> w,v, tail;

void knapsack1(int step, vector<int> &sol){
    if(step<n){
        sol[step] = 1; knapsack1(step+1, sol);
        sol[step] = 0; knapsack1(step+1, sol);
    } else {
        float sumV = 0;
        float sumW = 0;
        for(int i=0; i<n; i++){
            if(sol[i] == 1){
                sumV += v[i];
                sumW += w[i];
            }
        }
        if(sumV > maxV && sumW <= cap) maxV = sumV;
    }
}

//caculate sumV and sumW on fly
void knapsack2(int step, vector<int> &sol, float sumV, float sumW){
    // backtracking
    if(sumW>cap) return;
    if(step<n){
        sol[step] = 1;
        knapsack2(step+1, sol, sumV+v[step], sumW+w[step]);
        sol[step] = 0; 
        knapsack2(step+1, sol, sumV, sumW);
    } else {
        if(sumV > maxV && sumW <= cap) maxV = sumV;
    }
}

//branch and bound
void knapsack(int step, vector<int> &sol, float sumV, float sumW){
    if(sumW > cap) return;
    if(sumV > maxV && sumW<=cap) maxV = sumV;
    //B&B
    if(sumV + tail[step] < maxV) return;
    if(step < n){
        sol[step] = 1;
        knapsack(step+1, sol, sumV+v[step], sumW+w[step]);
        sol[step] = 0;
        knapsack(step+1,sol,sumV,sumW);
    } else {
        if(sumV> maxV && sumW<=cap) maxV = sumV;
    }
}

int main(){
    cin >> cap >> n;
    float tempsumV =0;
    v.resize(n);
    w.resize(n);
    for(int i=0; i<n; i++){
        float tmp;
        cin >> tmp;
        tempsumV += tmp;
        v[i] = tmp;
    }
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    tail.resize(n);
    tail[0] = tempsumV; 
    for(int i = 1; i<n; i++){
        tail[i] = tail[i-1] - v[i-1];
    }
    maxV = 0.0f;
    vector<int> sol(n,0);
    // knapsack1(0,sol);
    // knapsack2(0,sol,0,0);
    knapsack(0,sol,0,0);
    cout << fixed << setprecision(4) << maxV;
}