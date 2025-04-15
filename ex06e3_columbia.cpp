#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> t(r,vector<int>(c));
    int n = r*c;

    vector<vector<int>> g(n);
    vector<vector<int>> w(n,vector<int>(n));
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int tmp;
            cin >> tmp;
            t[i][j] = tmp;
            if(i>0) w[]
        }
    }


    vector<vector<int>> dist(n,vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            dist[i][j] = g[i][j];
        }
    }
}