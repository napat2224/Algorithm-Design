#include <iostream>

using namespace std;

void recur(string a, int k, int n,int count){
    if(count > k) return;
    if(a.size()==n) {
        if(count == k) cout << a << "\n";
        return;
    } 
    recur(a+"0",k,n,count);
    recur(a+"1",k,n,count+1);
}

int main(){
    int n,k;
    cin >> k >> n;
    // string a(n,'0');
    recur("",k,n,0);
}