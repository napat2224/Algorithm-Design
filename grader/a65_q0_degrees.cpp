#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;
    // vector<vector<int>> v(n,vector<int> (n));
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cin >> v[i][j];
    //     }
    // }
    vector<int> d(n);
    int max = 0;
    for(int i=0; i<n; i++){
        int count = 0;
        int x;
        for(int j=0; j<n; j++){
            cin >> x;
            if(x == 1) count += 1;
        }
        if(count > max) max = count;
        d[count]+=1;
    }

    for(int i=0; i<=max; i++){
        cout << d[i] << " ";
    }


}