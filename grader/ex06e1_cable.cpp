#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> w(n,vector<int>(n,-1));
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int tmp;
            cin >> tmp;
            w[i][j] = tmp;
            w[j][i] = tmp;
        }
    }

    vector<int> cost(n,INT_MAX);
    vector<int> prev(n,-1); // (u,prev(u))
    vector<bool> taken(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; //weight , node
    q.push(make_pair(0,0)); // itself
    cost[0] = 0;
    while(!q.empty()){
        pair<int,int> u = q.top();
        q.pop();
        if (taken[u.second]) continue; 
        taken[u.second] = true;
        for(int v=0; v<n; v++){
            if(cost[v] > w[u.second][v] && !taken[v]){
                cost[v] = w[u.second][v];
                prev[v] = u.second;
                q.push(make_pair(cost[v],v));
            }
        }
    }
    int result = 0;
    for(auto x:cost){
        result += x;
    }
    cout << result;
}