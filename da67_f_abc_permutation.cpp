#include <iostream>
#include <vector>
using namespace std;

bool check_valid(string& x, int a, int b, int c){
    int ca =0 ,cb=0,cc=0;
    for(auto it = x.begin(); it != x.end(); it++){
        if(*it == 'x') return false;
        else if(*it == 'A') ca++;
        else if(*it == 'B') cb++;
        else if(*it == 'C') cc++;
        else return false;
        if(ca > a || cb > b || cc >c) return false;
    }
    return true;
}

void change_column(string x, int idx,int a,int b,int c,vector<string>& v){
    if (idx >= x.size()) return;
    // if (check_valid(x,a,b,c)) v.push_back(x);

    x[idx] = 'A';
    if (check_valid(x,a,b,c)) v.push_back(x);
    change_column(x,idx+1,a,b,c,v);

    x[idx] = 'B';
    if (check_valid(x,a,b,c)) v.push_back(x);
    change_column(x,idx+1,a,b,c,v);

    x[idx] = 'C';
    if (check_valid(x,a,b,c)) v.push_back(x);
    change_column(x,idx+1,a,b,c,v);

}

int main(){
    int n,a,b,c;
    vector<string> v;
    cin >> n >> a >> b >> c;
    string x(n,'x');
    change_column(x,0,a,b,c,v);
    cout << v.size();
    for(auto &x: v){
        cout << "\n" << x;
    }
}