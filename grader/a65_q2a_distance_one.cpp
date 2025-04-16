#include <iostream>
#include <vector>
using namespace std;
int n, k;
int my_count;
vector<vector<int>> p;

int recur(int mysize, int available_in){
    if(mysize == n) {
        my_count += 1;
        return 1;
    }
    if(p[mysize][available_in] != 0) {
        return p[mysize][available_in];
    }
    else{
        if(available_in <= 0){
            int r1 = recur(mysize+1,k-1) %100000007;
            int r2 = recur(mysize+1,0) %100000007;
            p[mysize+1][k-1] = r1;
            p[mysize+1][0] = r2;
            p[mysize][available_in] = (r1+r2)%100000007;
            return (r1 + r2)%100000007;
        }else{
            int r3 = recur(mysize+1,available_in-1) %100000007;
            p[mysize+1][available_in-1] = r3;
            p[mysize][available_in] = r3;
            return r3;
        }
    }
    
}

int main(){
    cin >> n >> k;
    string s = "";
    my_count = 0;
    p.resize(n+1,vector<int>(k+1));
    cout << recur(0,0);
    // cout << my_count%100000007;
}