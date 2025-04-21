#include <iostream>
#include <vector>

using namespace std;

int n, maxP;
vector<int> b;
vector<vector<int>> f;
vector<int> tail;


/*
test case:
4
1 2 3 4
1 0 1 1
0 1 0 1
1 0 1 1
1 1 1 1
output : 8
*/

bool check(int idx, vector<int> &sol){
    for(int i=0; i<n; i++){
        if(sol[i] == 0) continue;
        if(f[idx][i] == 0) return false;
    }
    return true;
}

void team(int idx, vector<int> &sol, int totalPow){
    maxP = (totalPow> maxP)? totalPow:maxP;
    if(idx >= n) return;
    if((totalPow+tail[idx]<=maxP)) return;
    sol[idx] = 1;
    if(check(idx,sol)) team(idx+1,sol,totalPow + b[idx]);
    sol[idx] = 0;
    team(idx+1,sol,totalPow);
    for(int i=0; i<n; i++){
        if(sol[i] == 1) {
            used[i] =1;
        }
    }
}

int main(){
    cin >> n;
    b.resize(n);
    f.resize(n, vector<int>(n));
    used.resize(n);
    int tmpPower =0;
    for( int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        tmpPower += tmp;
        b[i] = tmp;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> f[i][j];
        }
    }
    tail.resize(n);
    tail[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        tail[i] = tail[i + 1] + b[i];
    }
    maxP = 0;
    vector<int> sol(n);
    team(0,sol,0);
    cout << maxP;
}