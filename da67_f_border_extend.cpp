#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> t(r, vector<int>(c));
    queue<pair<int,int>> q;
    vector<vector<int>> dist(r,vector<int>(c,-1));
    for (int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int tmp;
            cin >> tmp;
            t[i][j] = tmp;
            if(tmp == 1){
                q.push(make_pair(i,j));
                dist[i][j] = 0;
            }
        }
    }  

    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        if(t[u.first][u.second] == 0){
            t[u.first][u.second] = 2;
        }

        //up
        if(u.first>0 && dist[u.first-1][u.second]==-1){
            dist[u.first-1][u.second] = dist[u.first][u.second]+1;
            if(dist[u.first-1][u.second] <= k){
                q.push(make_pair(u.first-1,u.second));
            }
        }
        //down
        if(u.first<r-1 && dist[u.first+1][u.second]==-1){
            dist[u.first+1][u.second] = dist[u.first][u.second]+1;
            if(dist[u.first+1][u.second] <= k){
                q.push(make_pair(u.first+1,u.second));
            }
        }
        //left
        if(u.second>0 && dist[u.first][u.second-1]==-1){
            dist[u.first][u.second-1] = dist[u.first][u.second]+1;
            if(dist[u.first][u.second-1] <= k){
                q.push(make_pair(u.first,u.second-1));
            }
        }
        //right
        if(u.second<c-1 && dist[u.first][u.second+1]==-1){
            dist[u.first][u.second+1] = dist[u.first][u.second]+1;
            if(dist[u.first][u.second+1] <= k){
                q.push(make_pair(u.first,u.second+1));
            }
        }

    }

    for(auto &a:t){
        for(auto &b:a){
            cout << b << " ";
        }
        cout << "\n";
    }
}
