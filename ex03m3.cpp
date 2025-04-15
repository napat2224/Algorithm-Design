#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> cost;
vector<vector<int>> p;

/*
5 1 
1 99 1 99 1

5 1 
99 1 99 1 99

7 3 
1 2 3 4 3 2 1
*/

int recur( int idx, int space){
    if(idx >= n) return 0;
    if(p[idx][space] != -1) return p[idx][space];
    if(idx == n-1 && space > k){
        // cout << "\nforce to choose1: " << idx;
        int r3 = recur(idx+1,0) + cost[idx];
        p[idx][space] = r3;
        return r3;
    }else{
        if(space < k*2){
            int r2 = recur(idx+1,0) + cost[idx];
            int r1 = recur(idx+1,space+1);
            int tmp = min(r1,r2);
            // if (tmp == r1) cout << "\nchoose r1: " << idx;
            // else cout << "\nchoose r2: " << idx;
            p[idx][space] = tmp;
            return tmp;
        }else{
            // cout << "\nforce to choose2: " << idx;
            int r3 = recur(idx+1,0) + cost[idx];

            p[idx][space] = r3;
            return r3;
        }
    }
    
    
}

int main(){
    cin >> n >> k;
    cost.resize(n);
    p.resize(n+1,vector<int>(k*2+1,-1));
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    cout << recur(0,k);
}