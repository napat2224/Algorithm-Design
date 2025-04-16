#include <iostream>
#include <cmath>
using namespace std;
int n, k;

bool isDivoc(string s,int start, int stop, bool isFlip){
    if(isFlip){
        for(int i = 0; i<(stop-start+1)/2; i++){
            int tmp = s[start+i];
            s[start+i] = s[stop-i];
            s[stop-i] = tmp;
        }
    }
    if(stop-start == 1){
        if(s.substr(start,stop-start+1) == "01") return true;
        else return false;
    }
    int half = (start+stop)/2;
    return (isDivoc(s, start, half, true)||isDivoc(s, start, half, false)) && isDivoc(s, half+1, stop, false);
}

int main(){
    cin >> n >> k;
    int r = pow(2,k);
    for(int i=0; i<n; i++){
        string s;
        for(int j=0; j<r/2; j++){
            int a, b;
            cin >> a >> b;
            s += to_string(a) + to_string(b);
        }
        if( isDivoc(s,0,r-1, false) ) cout << "yes\n";
        else cout << "no\n";
    }
}