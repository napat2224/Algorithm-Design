#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <tuple>

using namespace std;

/*
test1:
6 3
5 3 3
4 3 3
output: 7.0000

test2:
5.5 4
2 3 4 5
1 2 3 4
output: 8.3333
*/
double cap, n;
vector<double> v;
// vector<pair<double,double>> vpw; // <value/weight,weight>
vector<tuple<double,double,double>> items; // <vpw,value,weight>

bool mycomp(tuple<double,double,double> &a, tuple<double,double,double> &b){
    if(get<0>(a)!=get<0>(b)) return get<0>(a)>get<0>(b);
    if(get<1>(a)!=get<1>(b)) return get<1>(a)>get<1>(b);
    return get<2>(a)>get<2>(b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> cap >> n;
    v.resize(n);
    // vpw.resize(n);
    items.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        double tmpw;
        cin >> tmpw;
        double tvpw = v[i]/tmpw;
        items[i] = make_tuple(tvpw,v[i],tmpw);
        // vpw[i] = make_pair(tvpw, tmp);
    }
    // sort(vpw.begin(), vpw.end(), mycomp);
    sort(items.begin(), items.end(), mycomp);
    // for(auto &x: vpw){
    //     cout << fixed << setprecision(4) << x.first << " " << x.second << "\n";
    // }
    double curW = 0;
    double curV = 0;
    for(int i=0; i<n; i++){
        if(curW >= cap) break;
        // if((vpw[i].second)+curW <= cap) {
        //     curV += vpw[i].first*vpw[i].second;
        //     curW += vpw[i].second;
        //     continue;
        // }
        // curV += vpw[i].first*(cap-curW);
        if(get<2>(items[i])+curW <= cap){
            curV += get<1>(items[i]);
            curW += get<2>(items[i]);
        } else {
            curV += get<0>(items[i]) * (cap-curW);
            curW = cap;
            break;
        }
    }
    cout << fixed << setprecision(4) << curV;
}