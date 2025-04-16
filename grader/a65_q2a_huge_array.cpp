#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*
1 1
10 2
5 1
1 1
3 1
-> 2,1 3,3 4,5 6,10
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    map<int,int> m;
    for(int i=0; i<n; i++){
        int tmp, x;
        cin >> tmp >> x;
        m[tmp] += x;
    }

    vector<pair<int,int>> v ;// (index,number)
    int count = 0;
    for(auto j = m.begin(); j!=m.end(); j++){
        count += j->second;
        v.push_back(make_pair(count,j->first));
    }
    for(int i=0; i<q; i++){
        int tmp;
        cin >> tmp;
        auto it = upper_bound(v.begin(),v.end(),make_pair(tmp,0));
        cout << it->second << "\n";
    }
}