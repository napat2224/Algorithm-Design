#include <iostream>
#include <vector>
using namespace std;

int row,col,k;
vector<vector<int>> A;

int main(){
    cin >> row >> col >> k;
    A.resize(row,vector<int>(col));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> A[i][j];
        }
    }

    vector<vector<int>> p(row,vector<int>(col));
    p[0][0] = A[0][0];
    for(int j=1; j<col; j++){
        p[0][j] = p[0][j-1] + A[0][j];
    } 
    for(int i=1; i<row; i++){
        p[i][0] = p[i-1][0] + A[i][0];
        for(int j=1; j<col; j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
        }
    }
    // cout << "\n----\n";
    for(int i=0; i<k; i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // cout << "("<<r1<<","<<c1<<") (" << r2 <<","<<c2<<")\n";
        int ans = p[r2][c2];
        // while(1){
            if(c1>0){
                ans -= p[r2][c1-1];
                // c1--;
            }
            if(r1>0){
                ans -= p[r1-1][c2];
                // r1--;
            }
            if(r1>0 && c1>0){
                ans += p[r1-1][c1-1]; 
            }
        // }
        cout << ans << "\n";
    }
}