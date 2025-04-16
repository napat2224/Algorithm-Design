#include <iostream>

using namespace std;

int compute(int x, int n, int k){
    if(n == 0) return 1%k;
    if(n == 1) return x%k;
    if(n % 2 == 0){
        int temp = compute(x,n/2,k);
        return (temp * temp)%k;
    }
    int half = n/2;
    return (compute(x,half,k) * compute(x,n-half,k)) % k;
}

int main(){
    int x, n, k;
    cin >> x >> n >> k;
    cout << compute(x,n,k);
}