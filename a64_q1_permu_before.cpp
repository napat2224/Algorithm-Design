#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool check_valid(vector<int> sol, map<int,int> &v){
    map<int,int>::iterator it = v.find(sol[sol.size()-1]);
    bool found_front = it==v.end();
    for(int i=0; i<sol.size()-1;i++){
        if(sol[i] == sol[sol.size()-1]) return false;
        if(it!=v.end()){
            if(sol[i]==it->second) found_front = true;
        }
    }
    return found_front;
}
void recur(vector<int> sol, map<int,int> &v, int n,int myBack){
    sol.push_back(myBack);
    if(sol.size() > n) return;
    if(!check_valid(sol,v)) return;
    if(sol.size()==n) {
        for(auto x:sol) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        recur(sol,v,n,i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    map<int,int> v;
    for(int i=0; i<m;i ++){
        int a, b;
        cin >> a >> b;
        v[b] = a;
    }
    vector<int> sol;
    for(int i=0;i<n;i++) recur(sol,v,n,i);
}
