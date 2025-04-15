#include <iostream>
#include <vector>

using namespace std;

/*
7 5 2
4 6 2 7 3 5 9
1 1
1 6
1 14
4 7
6 3 
*/
int k, m, n;
vector<int> d,p,w;
vector<vector<int>> r;

int R(int start, int remain){
    if(start >= n) return n;
    if(d[start] >= remain) return start;
    if(remain <= 0) return start-1;
    if(r[start][remain] != -1) return r[start][remain];
    int r1 = R(start+1,remain-d[start]);
    r[start][remain] = r1;
    return r1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> m;
    d.resize(n+1);
    p.resize(k+1);
    w.resize(k+1);
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        d[i] = tmp-m;
    }
    int max_w=-1;
    for(int i=1; i<=k; i++){
        cin >> p[i] >> w[i];
        if(w[i] > max_w) max_w = w[i];
    }
    r.resize(n+1,vector<int>(max_w+1,-1));
    for(int i=1; i<=k; i++){
        cout << R(p[i],w[i]) << "\n";
    }

}
