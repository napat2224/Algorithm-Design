#include <iostream>
#include <vector>

using namespace std;
string a,b;

/*
acbdegcedbg begcfeubk
-> 6
*/

int LCS_recur(int i, int j){
    if(i<0 || j<0) return 0;
    if(a[i] == b[j]) return LCS_recur(i-1,j-1) + 1;
    return max(LCS_recur(i,j-1),LCS_recur(i-1,j));
}

vector<vector<int>> v;

int LCS_top(int i, int j){
    if(i<0 || j<0) return 0;
    if(v[i][j]!=-1) return v[i][j];
    if(a[i] == b[j]) {
        int tmp =  LCS_top(i-1,j-1) + 1;
        v[i][j] = tmp;
        return tmp;
    }
    int tmp = max(LCS_top(i,j-1),LCS_top(i-1,j));
    v[i][j] = tmp;
    return tmp;
}

int LCS_bottom(int i, int j){
    for(int p = 0; p<= i; p++){
        for(int q=0; q<= j;q++){
            if(p==0||q==0) v[p][q] = 0;
            else if(a[p] == b[q]) v[p][q] = v[p-1][q-1] + 1;
            else v[p][q] = max(v[p][q-1],v[p-1][q]);
        }
    }
    return v[i][j];
    // return 0;

}

int main(){
    cin >> a >> b;
    // v.resize(a.size(), vector<int>(b.size(),-1));
    // cout << LCS_top(a.size()-1,b.size()-1);
// for bottomup
    v.resize(a.size()+1, vector<int>(b.size()+1));
    a = ' ' + a;
    b = ' ' + b;
    cout << LCS_bottom(a.size()-1,b.size()-1);
}