// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>> g;
vector<vector<int>> dist;

void fw(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(g[i][j] == -1) dist[i][j] = 100000;
            else if(i == j) dist[i][j] = 0;
            else dist[i][j] = g[i][j];
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // if(g[i][j] == -1) dist[i][j] = dist[i][j];
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

void bd(){

}

int main(){
    cin >> n >> m;
    g.resize(n+1, vector<int>(n+1,-1)); //start at 1
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    dist.resize(n+1, vector<int>(n+1,0)); //start at 1
    fw();
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            // cout << dist[i][j] << " ";
            if(i==j) continue;
            if(dist[i][j] > ans) ans = dist[i][j];
        }
        // cout << "\n";
    }
    cout << ans;

}