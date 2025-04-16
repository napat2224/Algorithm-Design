#include <iostream>

using namespace std;

int A[31][31];

int bino_naive(int n, int r){
    if(r == n|| r == 0) return 1;
    return bino_naive(n-1,r) + bino_naive(n-1,r-1);
}

int bino_top_down(int n, int r){
    if(r == n|| r == 0) return 1;
    if(A[n][r] > 0) return A[n][r];
    int result = bino_naive(n-1,r) + bino_naive(n-1,r-1);
    A[n][r] = result;
    return result;
}

//pascal (just one way to do)
int bino_bottom_up(int n, int r){
    // every r = 0, r =n is 1
    for(int i=0; i<=n; i++){
        A[i][0] = 1;
        A[i][i] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            // additional
            if(j>r) break;
            A[i][j] = A[i-1][j] + A[i-1][j-1];
        }
    }
    return A[n][r];
}

int main(){
    int n, r;
    cin >> n >> r;
    cout << bino_bottom_up(n,r);
}