// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
test:
4 4
10 20 30 40 50 60 70 80
0 1 10
0 2 15
1 2 5
0 3 35
out: y y n n y n n n
*/

int n,m;
vector<int> k(8);
vector<vector<int>> g;


void mys(int cur, vector<int>&used, int cost, int target, bool &ans){
    if(ans) return;
    if(cost == target) {
        ans = true;
        return;
    }
    if(cost > target) {
        used[cur] = -1;
        return;
    }
    if(cur == -1) {
        vector<int> newUsed(n,-1);
        for(int i=0; i<n; i++){
            mys(i,newUsed,0,target,ans);
        }
    }else{
        used[cur] = 1;
        for(int i=0; i<n; i++){
            if(used[i]==-1 && g[cur][i] != -1){
                used[i] = 1;
                mys(i,used,cost+g[cur][i],target,ans);
                used[i] = -1;
            }
        }
        used[cur] = -1;
    }
}

void BestFS(){
    
}

int main(){
    cin >> n >> m;
    g.resize(n, vector<int> (n,-1));

    for(int i=0; i<8; i++){
        cin >> k[i];
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    for(int i=0; i<8; i++){
        bool ans = false;
        vector<int> used(n,-1);
        mys(-1,used,0,k[i],ans);
        cout << ans << "\n";
    }
}