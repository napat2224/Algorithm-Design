#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> m(100, vector<int>(100));
vector<vector<int>> dist(100,vector<int>(100,-1));
queue<pair<int,int>> q;
int r,c;

void bfs(){
    q.push(make_pair(0,0));
    dist[0][0] = 0;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        if(u.first >= 1 && m[u.first-1][u.second] == 1 && dist[u.first-1][u.second] == -1){
            q.push(make_pair(u.first-1,u.second));
            dist[u.first-1][u.second] = dist[u.first][u.second] + 1;
        }
        if(u.first < r-1 && m[u.first+1][u.second] == 1 && dist[u.first+1][u.second] == -1){
            q.push(make_pair(u.first+1,u.second));
            dist[u.first+1][u.second] = dist[u.first][u.second] + 1;
        }
        if(u.second >= 1 && m[u.first][u.second-1] == 1 && dist[u.first][u.second-1] == -1){
            q.push(make_pair(u.first,u.second-1));
            dist[u.first][u.second-1] = dist[u.first][u.second] + 1;
        }
        if(u.second < c-1 && m[u.first][u.second+1] == 1 && dist[u.first][u.second+1] == -1){
            q.push(make_pair(u.first,u.second+1));
            dist[u.first][u.second+1] = dist[u.first][u.second] + 1;
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<c; j++){
            m[i][j] = (tmp[j] == '.')? 1:0;
        }
    }
    bfs();
    cout << dist[r-1][c-1];
}