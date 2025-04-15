#include <iostream>
#include <vector>
using namespace std;
/*
5 3 1 4 5 2
-> 3
13 7 0 10 21 1 6 22 4 3 5 9 8 71
-> 6
*/
vector<int> a;
vector<vector<int>> b;

int LIS(int idx, int prev_idx){
    if(idx == a.size()) return 0;
    if(b[idx][prev_idx] != -1) return b[idx][prev_idx];
    if(a[idx] > a[prev_idx]) {
        int tmp = max(LIS(idx+1,idx)+1, LIS(idx+1,prev_idx));
        b[idx][prev_idx] = tmp;
        return tmp;
    } 

    int tmp = LIS(idx+1,prev_idx);
    b[idx][prev_idx] = tmp;
    return tmp;
}

int main(){
    int n;
    cin >> n;
    a.resize(n+1);
    b.resize(n+1,vector<int>(n+1,-1));
    a[0] = -1;
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    cout << LIS(0,0);
}