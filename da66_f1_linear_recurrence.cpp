#include <iostream>
#include <vector>
using namespace std;
int k;
vector<int> a,c;
vector<int> r(1001,40000);

/*
2 4 10 -1 2 10
-> 9602
*/

int R(int n){
    if(n<k) return a[n];
    // cout << "call R"<< n << " r(n) = " << r[n] << "\n";
    if(r[n] != 40000) return r[n];
    int result = 0;
    for(int i=1; i<=k; i++){
        result += c[i]*R(n-i);
        result = result % 32717;
        // cout << result << "r ";
    }
    r[n] = result % 32717;
    return result;
}

int main(){
    int n;
    cin >> k >> n;
    c.resize(k+1);
    a.resize(k);
    c[0] = 0;
    for(int i=1; i<=k; i++){
        cin >> c[i];
    }
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    // cout << "\n";
    // for(auto x:r){
    //     cout << x << " ";
    // }
    // cout << "\n";
    cout << R(n);
}