#include <iostream>
#include <vector>

using namespace std;

int n, m;
string X, Y;
vector<vector<int>> l;

int main(){
    cin >> n >> m;
    cin >> X >> Y;
    l.resize(n+1,vector<int>(m+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cin >> l[i][j];
        }
    }
    int a = n; 
    int b = m;
    string ans = "";
    while(1){
        if(a==0 || b==0) break;
        if(l[a][b] == l[a-1][b-1] + 1) {
            ans = X[a-1] + ans;
            a--; b--;
        }else{
            if(l[a][b] == l[a-1][b]){
                a--;
            }else{
                b--;
            }
        }
    }
    cout << ans;
}