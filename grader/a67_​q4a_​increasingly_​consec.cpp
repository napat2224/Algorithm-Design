#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;
vector<pair<long long,long long>> v;
map<long long,long long> m; //(card, frequence)

int main(){
    cin >> n;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        m[a]++;
    }  
    // v.resize(m.size()); // start at 1
    auto it = m.begin();
    while(it!=m.end()){
        v.push_back(make_pair(it->second,it->first));
        it++;
    }
    sort(v.begin(),v.end());
    // for(auto x:v){
    //     cout << x.first << " " << x.second << "\n";
    // }

    //count
    long long count =0;
    for(auto &x:v){
        if(x.first == 1) continue;
        long long tmp = x.first * x.first;
        count += tmp;
    }
    cout << count;
}
// greedy

/*
5
1 3 5 7 9

*/