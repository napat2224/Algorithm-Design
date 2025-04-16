#include <iostream>

using namespace std;

string plus_one(string &a) {
    for(int i =a.size()-1; i>=0; i--){
        // cout << "here is i:" << i << "\n";
        // cout << "here is a[i]:" << a[i] << "\n";
        if(a[i] == '0') {
            a[i] = '1';
            return a;
        }else{
            a[i] = '0';
        }
    }
    return a;
}

bool check_valid(string &a , int k) {
    int count = 0;
    for(auto x:a){
        if(x == '1') count++;
        else count = 0;
        if(count == k) return true;
    }
    return false;
}

int main() {
    int n,k;
    cin >> n >> k;
    string a(n,'0');
    string b(n,'1'); 
    while (a != b) {
        if(check_valid(a,k))cout << a << "\n";
        plus_one(a);
    }
    if(check_valid(a,k))cout << a << "\n";
    
}

// 0 0 0
// 0 0 1
// 0 1 0
// 0 1 1
// 1 0 0