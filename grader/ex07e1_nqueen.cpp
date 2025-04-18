#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> col;
vector<bool> used;

bool check(int c){
    for (int i = 0; i < c; i++) {
        if ( abs(col[c] - col[i]) == c - i)
            return false;
    }
    return true;
}

void nqueen(int c ,int &count){
    if(c == n){
        count++;
        return;
    } else {
        for (int i=0; i<n; i++){
            if(!used[i]) {
                used[i] = true;
                col[c] = i;
                if(check(c)) nqueen(c+1,count);
                used[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    col.resize(n,-1);
    used.resize(n);
    int count =0;
    nqueen(0,count);
    cout << count;
}