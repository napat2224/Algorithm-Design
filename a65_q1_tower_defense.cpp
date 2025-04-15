#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void shoot(int mon, vector<int> &h, vector<int> &p, set<int> &mons){
    // cout << "shoot " << mon << "\n";
    auto idx = find(p.begin(),p.end(),mon)-p.begin();
    h[idx]-=1;
    // cout << idx << "------\n";
    if(h[idx] == 0){
        h.erase(h.begin()+idx);
        p.erase(p.begin()+idx);
        mons.erase(mon);
    }
}

int main(){
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> p;
    vector<int> h;
    vector<int> t;
    set<int> mons;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
        mons.insert(tmp);
    }
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        h.push_back(tmp);
    }
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    sort(t.begin(),t.end());
    // cout << "p:";
    // for(auto x:p) cout << x <<" ";
    // cout << "\nh:";
    // for(auto x:h) cout << x <<" ";
    // cout << "\nt:";
    // for(auto x:t) cout << x <<" ";
    // cout << "\n";
    for(auto x:t){
        // cout << "this is for x = " << x << "\n";
        for(int i=0; i<=w; i++){
            // cout << "check " << x+i << "\n";
            if(mons.find(x+i) != mons.end()){
                // cout << "shoot from" << x << "\n";
                shoot(x+i,h,p,mons);
                break;
            }
            if(mons.find(x-i) != mons.end()){
                // cout << "shoot from" << x << "\n";
                shoot(x-i,h,p,mons);
                break;
            }
        }
    }
    int result =0;
    for(auto x:h){
        result += x;
    }
    cout << result;
}