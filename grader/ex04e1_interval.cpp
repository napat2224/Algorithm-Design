#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
test case1:
3
1 4 6
5 7 10
output : 2

test2:
4
1 2 3 4 
2 3 4 5
output: 4
*/

int n;
vector<pair<int,int>> t; // <stop,start>
int curStop;

int main(){
    cin >> n;
    t.resize(n);

    for(int i=0; i<n; i++){
        cin >> t[i].second;
    }
    for(int i=0; i<n; i++){
        cin >> t[i].first;
    }

    sort(t.begin(),t.end());
    // for(auto &x: t){
    //     cout << x.first << " " << x.second << "\n";
    // }
    int result = 0;
    curStop = -1;
    for(auto &x: t){
        if(x.second >= curStop) {
            curStop = x.first;
            result++;
        }
    }
    cout << result;
}