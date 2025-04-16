#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,e,k;
vector<vector<int>> adjlist(1001);

int bfs(int start){
    // cout << "start at " << start << "\n";
    int result = 1;
    vector<int> visited(n,-1);
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u] >= k) return result;
        for(auto x:adjlist[u]){
            if(visited[x]!=-1) continue;
            visited[x] = visited[u]+1;
            result++;
            q.push(x);
        }
    }
    return result;
}

int main(){
    cin >> n >> e >> k;

    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int result = 0;
    for(int i=0; i<n; i++){
        result = max(result,bfs(i)); 
    }
    cout << result;
}