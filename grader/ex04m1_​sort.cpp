// #include <bits/stdc++.h>
// #include <iomanip>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        m[tmp]++;
    }
    int one_end = m[1];
    int two_end = m[1]+m[2];

    vector<vector<int>> misplace(4, vector<int>(4,0));
    // misplace[2][3] mean how mnay 3 that in place of 2

    for(int i=0; i<n; i++){
        int shouldbe;
        if(i < one_end) shouldbe = 1;
        else if(i < two_end) shouldbe = 2;
        else shouldbe = 3;

        if(v[i] != shouldbe) misplace[shouldbe][v[i]]++; 
    }

    int count = 0;

    //direct swap
    for(int i=1; i<=3; i++){
        for(int j=i+1; j<=3; j++){
            int tmp = min(misplace[i][j], misplace[j][i]);
            count += tmp;
            misplace[i][j] -= tmp;
            misplace[j][i] -= tmp;
        }
    }

    //3 cycle
    //swap 2 in 1 place with 3 in 1 place
    int remain = misplace[1][2] + misplace[1][3];
    count += 2*(remain/2); //1 cycle contain 3 misplace

    cout << count;
}