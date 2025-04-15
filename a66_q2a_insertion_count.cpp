#include <iostream>
#include <vector>

using namespace std;
/*
10 5
10 9 8 3 1 4 2 5 7 6
6 2 8 5 7
4 5 2 3 3
how much number more than that number and infront of that number
*/
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
    }
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        int count = 0;
        for(int j=0; j<n; j++){
            if(a[j] == temp){
                cout << count << "\n";
                break;
            }
            if(a[j] > temp) count++;
        }
    }
    
}