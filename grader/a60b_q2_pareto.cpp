#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;

/*
3 50 10 30 30 10 50
-> 3
3 10 10 20 20 30
-> 1
*/

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());

    int i = v.size()-1;
    while(i>0){
        int j = i -1;
        cout << " hi \n";
        while(j>=0){
            cout << i << " " << j << "\n";
            if(v[j].second <= v[i].second) {
                // v.erase(v.begin()+j);
                i--;
                j--;
            }else {j--;}
        }
        i--;
    }
    cout << v.size();
}