#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <climits>

using namespace std;

/*
test1:
2 2
1 1 2 2
4 5
6 7
out: 11

test2:
4 5
2 1 4 5
3 4 222 666 1
4 5 2 1 25
19 18 20 40 9999
777 1 299 13 10
out: 54
*/

int R, C;
int a1 , b1, a2, b2;
int minCost;
vector<vector<int>> hexMap;
vector<vector<int>> dist;

const int dr_even[6] = {0,0,-1,-1,1,1};
const int dc_even[6] = {-1,1,0,1,0,1};
const int dr_odd[6] = {0,0,-1,-1,1,1};
const int dc_odd[6] = {-1,1,-1,0,-1,0};

int main(){
    cin >> R >> C;
    hexMap.resize(R, vector<int> (C));
    dist.resize(R, vector<int> (C,INT_MAX));
    cin >> a1 >> b1 >> a2 >> b2;
    a1--;a2--;b1--;b2--; //start at 0
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> hexMap[i][j];
        }
    }
    minCost = INT_MAX;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q; //cost from (a1,b1), r, c
    q.push(make_tuple(hexMap[a1][b1], a1, b1));
    dist[a1][b1] = hexMap[a1][b1];
    while(!q.empty()){
        tuple<int,int,int> u = q.top();
        int cost = get<0>(u);
        int r = get<1>(u);
        int c = get<2>(u);
        q.pop();
        for(int i=0; i<6; i++){
            int tr = (r%2==1)? r+dr_odd[i]: r+dr_even[i];
            int tc = (r%2==1)? c+dc_odd[i]: c+dc_even[i];
            if(tr>=0 && tr<R && tc>=0 && tc<C){
                int newCost = dist[r][c]+hexMap[tr][tc];
                if(newCost<=dist[tr][tc]){
                    dist[tr][tc] = newCost;
                    q.push(make_tuple(newCost, tr, tc));
                }
            }
        }
    }
    cout << dist[a2][b2];
}