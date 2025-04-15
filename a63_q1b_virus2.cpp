#include <iostream>
#include <cmath>

using namespace std;
//1 3 0 0 1 1 0 0 1 1
bool check(string &x, int start, int stop){
    if(stop-start == 1) return true;
    int half = (stop+start)/2;
    int count = 0;
    for(int i=0; i<=(stop-start)/2; i++){
        // if(x[start+i] == '1') count+= 1; cout<< start+i<<"plus ";
        // if(x[stop-i] == '1') count-=1; cout << stop-i<< "minus ";
            if(x[start+i] == '1') count+= 1;
        if(x[stop-i] == '1') count-=1;
    }
    // cout << "count of start: " << start << " stop: " << stop<< " count: " << count << "\n";
    if(count > 1 || count < -1) return false;
    return check(x,start,half) && check(x,half+1,stop);

}

int main(){
    int n, k;
    cin >> n >> k;
    int lenght = pow(2,k);
    for(int i=0; i<n; i++){
        string x = "";
        for(int j=0; j<lenght/2; j++){
            int a,b;
            cin >> a >> b;
            x += to_string(a) + to_string(b);
        }
        if(check(x,0,x.size()-1)) cout << "yes\n";
        else cout << "no\n";
    }
}