#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

bool my_recur(int a, int b, int c, int want, vector<vector<vector<int>>> &k){
    if(a == b || a == c || b == c || a>=n || b>=n || c>= n) return false;
    if(k[a][b][c] == 1) return true;
    if(k[a][b][c] == 2) return false;

    if(v[a]+v[b]+v[c] == want) {
        k[a][b][c] = 1;
        return true;
    }
    k[a][b][c] = 2;

    if(my_recur(a+1,b,c,want,k)) {
        k[a][b][c] = 1;
        return true;
    }
    if(my_recur(a,b+1,c,want,k)) {
        k[a][b][c] = 1;
        return true;
    }
    if(my_recur(a,b,c+1,want,k)) {
        k[a][b][c] = 1;
        return true;
    }
    k[a][b][c] = 2;
    return false;
}

int main(){
    cin >> n >> m;
    v.resize(n);
    vector<vector<vector<int>>> k(n,vector<vector<int>>(n, vector<int>(n,0)));
    for(int i=0; i< n; i++){
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        if(my_recur(0,1,2, tmp,k)) cout << "YES\n";
        else cout << "NO\n";
    }
}