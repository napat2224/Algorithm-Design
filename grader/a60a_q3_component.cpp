#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adjlist, vector<int> &visited, int &cc_num, int node){
    visited[node] = cc_num;
    for(auto &x:adjlist[node]){
        if(visited[x] == -1) dfs(adjlist, visited, cc_num, x);
        // cout << x << " ";
    }
}

int main(){

    int v, e;
    cin >> v >> e;
    vector<vector<int>> adjlist(v+1);
    vector<int> visited(v+1,-1);
    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int cc_num = 0;
    for(int i=1; i<=v; i++){
        if(visited[i] != -1) continue;
        cc_num++;
        dfs(adjlist,visited,cc_num,i);
    }
    cout << cc_num;
}