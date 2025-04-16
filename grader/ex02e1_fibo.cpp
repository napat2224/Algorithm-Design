#include <iostream>
#include <vector>

using namespace std;
// 1 1 2 3 5 8 13
vector<int> V;

int fibo_top_down(int x){
    if(x==1||x==0) return x;

    if(V[x] != 0) return V[x];
    int result = fibo_top_down(x-1) + fibo_top_down(x-2);
    V[x] = result;
    return result;
}

int fibo_bottom_up(int x){
    V[0] = 1;
    V[1] = 1;
    for(int i = 2;i<x; i++){
        V[i] = V[i-1] + V[i-2];
    }
    return V[x-1];
}

// less memory keep only last 2
// int fibo_opt(int x){

// }

int main(){
    int x;
    cin >> x;
    V.resize(x+1);
    // cout << fibo_top_down(x);
    cout << fibo_bottom_up(x);
}