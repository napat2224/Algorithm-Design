#include <iostream>
#include <vector>

using namespace std;

int n;

void iss(int sum, int last,int &count) {
    int a = last;
    if(sum > n) return;
    if(sum == n){
        count++;
        return;
    }
    for(int i=last; i+sum <= n; i++){
        iss(sum+i,i,count);
    }
        
    return;
}

int main(){
    cin >> n;
    int count =0;
    iss(0,1,count);
    cout << count;
}