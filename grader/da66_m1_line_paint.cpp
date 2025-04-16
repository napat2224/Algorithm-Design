#include <iostream>
#include <set>
using namespace std;

set<pair<int,int>> A;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){

        int a, b;
        cin >> a >> b;
        auto it = A.lower_bound(make_pair(a,b));

        if(A.size() == 0){
            A.insert(make_pair(a,b));
            continue;
        }
        if(it!=A.begin()) {
            it--;
            if(a <= it->second +1){
                a = it->first;
                b = max(b,it->second);
                it = A.erase(it);
                if(it == A.end()) {
                    A.insert(make_pair(a,b));
                    continue;
                }
            }else{it++;}
        }
    
        while(it != A.end() && b >= it->first-1){
            // if(b > it->first){
                b = max(b,it->second);
                a = min(a,it->first);
                it = A.erase(it);
            // }
        }
        A.insert(make_pair(a,b));
    }

    for(auto x: A){
        cout << x.first << " " << x.second << " ";
    }
}