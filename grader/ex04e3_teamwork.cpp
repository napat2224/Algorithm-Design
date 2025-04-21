#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
test1:
1 4
3 9 4 2
out: 8.500

test2:
3 10
4 3 2 4 1 2 5 3 4 5
out 6.100
*/

int n, m;
vector<float> t;
vector<pair<float,int>> mem; //<time,count>

int main(){
    cin >> n >> m;
    t.resize(m);
    for(int i=0; i<m; i++){
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    mem.resize(n);
    vector<float> last(n);
    for(int i=0; i<m; i++){
        mem[i%n].first += t[i]+last[i%n];
        last[i%n] += t[i];
        mem[i%n].second++;
    }
    float a=0;
    float b=0;
    for(int i=0; i<n; i++){
        a += mem[i].first;
        b += mem[i].second;
    }

    cout << fixed << setprecision(4) << a/b;
}