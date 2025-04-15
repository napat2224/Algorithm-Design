#include <iostream>
#include <vector>
using namespace std;

void walk(vector<vector<int>> &arr, string path, int r, int c){
    //check if the cell can walk into
    // cout << r << "," << c << "\n";
    if(arr[r][c] == 1) return;
    if(r == arr.size()-1 && c == arr[0].size()-1) {
        cout << path << "\n";
        return;
    }
    //try walk to the right (A)
    if(c < arr[r].size()-1) {
        walk(arr, path+"A", r,c+1);
    }
    //try walk to the bottom (B)
    if(r < arr.size()-1 && path[path.size()-1] != 'C') {
        walk(arr, path+"B", r+1,c);
    }
    //try walk to the above (C)
    if(r > 0 && path[path.size()-1] != 'B') {
        walk(arr, path+"C", r-1,c);
    }
}

void printarr( vector<vector<int>> arr, int r, int c){
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << arr[i][j] << " ";
        }
        cout <<"\n";
    }
}

int main(){
    int r,c;
    cin >> r >> c;
    vector<int> a(c);
    vector<vector<int>> arr(r,a);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    // printarr(arr,r,c);
    walk(arr,"",0,0);
    cout << "DONE";
}