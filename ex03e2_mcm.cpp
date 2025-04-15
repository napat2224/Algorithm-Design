#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> a;
vector<vector<int>> b;
int n;
/*
    mcm(x,x) = 0
    mcm(x,x+1) = a[x] * a[x+1] * a[x+2] 
*/

// D&C
int mcm_dac(int l,int r){
    if(r == l) return 0;
    int minCost = INT_MAX;
    for(int i=l; i<r; i++){
        int my_cost = mcm_dac(l,i) + mcm_dac(i+1,r) + 
            (a[l] * a[i+1] * a[r+1]);
        minCost = min(my_cost,minCost);
    }
    return minCost;
}

int mcm_top(int l,int r){
    if(r == l) return 0;
    if(b[l][r] != 0) return b[l][r];
    int minCost = INT_MAX;
    for(int i=l; i<r; i++){
        int my_cost = mcm_top(l,i) + mcm_top(i+1,r) +
            (a[l] * a[i+1] * a[r+1]);
        minCost = min(my_cost,minCost);
    }
    b[l][r] = minCost;
    return minCost;
    
}

// !อมก อยากจะรู้ว่าแบ่งยังไงด้วยถ้ามีเวลา
int mcm_bottom(int l, int r){
    for(int i=0; i<n; i++){
        b[]
    }
}

int main(){
    cin >> n;
    a.resize(n+1);
    for(int i=0; i<=n; i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    b.resize(n+1,vector<int>(n+1,0));
    cout << mcm_top(0,n-1);
}