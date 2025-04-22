// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
test1:
6 3 2 1 3 12 7 8
out: 3

test2:
5 6
2 4 9 11 14
out: 2
*/

int N, L;
vector<int> pi;

int main(){
    cin >> N >> L;
    pi.resize(N);
    for(int i=0; i<N; i++){
        cin >> pi[i];
    }
    sort(pi.begin(), pi.end());
    int curCover = pi[0]+L-1;
    int count = 1;
    for(int i=1; i<N; i++){
        if(pi[i] > curCover){
            curCover = pi[i] + L - 1;
            count++;
        }
    }
    cout << count;
}