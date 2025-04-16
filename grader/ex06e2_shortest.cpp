#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int n, e, s;
    cin >> n >> e >> s;

    vector<vector<int>> g(n);
    vector<vector<int>> w(n,vector<int>(n,INT_MAX));
    
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        w[a][b] = c;
    }

    // vector<vector<int>> d(n,vector<int> (n,INT_MAX)); 

    // d[0][s] = 0;
    // for(int i=1; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         d[i][j] = d[i-1][j];
    //     }
    //     for(int a=0; a<n; a++){
    //         for(auto &b:g[a]){
    //             if( d[i][b] > d[i][a] + w[a][b]){
    //                 d[i][b] = d[i][a] + w[a][b];
    //             }
    //         }
    //     }
    // }
    // for(auto &x:d[n-1]){
    //     cout << x << " ";
    // }

    vector<int> d(n,INT_MAX);

    d[s] = 0;
    for(int i=1; i<n; i++){
        for(int a=0; a<n; a++){
            for(auto &b: g[a]){
                if(d[a] == INT_MAX) continue;
                if(d[b] > d[a]+w[a][b]){
                    d[b] = d[a]+w[a][b];
                }
            }
        }
    }
    bool negCycle = false;
    for(int a=0; a<n; a++){
        for(auto &b: g[a]){
            if(d[b] > d[a]+w[a][b]){
                negCycle = true;
                break;
            }
        }
        if(negCycle) break;
    }

    if(negCycle) cout << -1;
    else{
        for(auto x:d){
            cout << x << " ";
        }
    }
}