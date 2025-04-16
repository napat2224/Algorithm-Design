#include <iostream>
using namespace std;

int A[3][3];
int B[3][3];
int C[3][3];
 
int main(){

/*
1 2 3 
2 3 4 
3 4 5 

2 3 4 
3 4 5 
4 5 6 

20 26 32
29 38 47
38 50 62
*/
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            A[i][j] = 1+i+j;
            B[i][j] = 2+i+j;
        }
    }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout << B[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}