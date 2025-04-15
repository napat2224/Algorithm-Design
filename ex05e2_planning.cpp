#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> innerDeg(n);
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            G[tmp].push_back(i);
            innerDeg[i]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(innerDeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto x:G[u]){
            innerDeg[x]--;
            if(innerDeg[x] == 0) q.push(x);
        }
    }
}