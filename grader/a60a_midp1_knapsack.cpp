#include <iostream>
#include <vector>

using namespace std;
/*
5 5
3 10 6 3 5
5 5 3 1 1
0 0 0 0 0 0
0 0 0 0 0 3
0 0 0 0 0 10
0 0 0 6 6 10
0 3 3 6 9 10
0 5 8 8 11 14
-> 3
-> 5 4 3

5 3
6 9 5 4 3
2 3 1 1 2
0 0 0 0
0 0 6 6
0 0 6 9
0 5 6 11
0 5 9 11
0 5 9 11
-> 1  or  2
-> 3      1 2

3 5
2 2 4
1 4 5
0 0 0 0 0 0
0 2 2 2 2 2
0 2 2 2 2 4
0 2 2 2 2 4
-> 1 3
*/

int n,cap;
vector<int> p,w;
vector<vector<int>> V;

//D&C
int knapsack(int idx, int remain){
    if(idx == 0) return 0;
    if(remain >= w[idx]){
        // r1 -> don't pick idx; r2 -> pick idx;
        int r1 = knapsack(idx-1,remain);
        int r2 = knapsack(idx-1, remain - w[idx]) + p[idx];
        return max(r1,r2);
    }else{
        return knapsack(idx-1,remain);
    }
}

int knapsack_2(int idx, int remain, vector<bool> &pick){
    if(idx == 0 || remain ==0) return 0;
    if(remain >= w[idx]){
        // r1 -> don't pick idx; r2 -> pick idx;
        int r1 = knapsack_2(idx-1,remain,pick);
        int r2 = knapsack_2(idx-1, remain - w[idx],pick) + p[idx];
        if(r1>r2){
            pick[idx] = false;
            cout << "\ndont pick " << idx;
            return r1;
        }else{
            pick[idx] = true;
            cout << "\npick " << idx;

            return r2;
        }
        // return max(r1,r2);
    }else{
        // int tmp = k
        pick[idx] = false;
        cout << "\ndont pick " << idx;
        return knapsack_2(idx-1,remain,pick);
    }
}

int knapsack_top(int idx, int remain) {
    if(idx == 0) return 0;
    if(V[idx][remain] != 0) return V[idx][remain];

    if(remain >= w[idx]){
        // r1 -> don't pick idx; r2 -> pick idx;
        int r1 = knapsack_top(idx-1,remain);
        int r2 = knapsack_top(idx-1, remain - w[idx]) + p[idx];

        int tmp = max(r1,r2);
        V[idx][remain] = tmp;
        return tmp;
    }else{
        int tmp = knapsack_top(idx-1,remain);
        V[idx][remain] = tmp;
        return tmp;
    }
}




int main(){
    cin >> n >> cap;
    p.resize(n+1);
    w.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }    
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    V.resize(n+1,vector<int>(cap+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=cap; j++){
            cin >> V[i][j];
        }
    }
// 5 3
// 6 9 5 4 3
// 2 3 1 1 2
// 0 0 0 0
// 0 0 6 6
// 0 0 6 9
// 0 5 6 11
// 0 5 9 11
// 0 5 9 11
    //! this already give bottom-up
    // vector<int> ans;
    string ans = "";
    int count = 0;
    int a = n;
    int b = cap;
    while(a>0&&b>0){
        if(b-w[a] >= 0 && V[a][b] == V[a-1][b-w[a]] + p[a]){
            count++;
            ans += to_string(a) + " ";
            b = b-w[a];
        }
        a--;
    }
    cout << count;
    cout << "\n" << ans;


    // vector<bool> pick(n+1,0);

    // // cout << "best price : " << knapsack_top(n,cap) << "\n";
    // // cout << "best price : " << knapsack_2(n,cap,pick) << "\n";
    // knapsack_2(n,cap,pick);

    // int count = 0;
    // string result = "";
    // for(int i=0; i<=n; i++){
    //     if(pick[i]){
    //         count++;
    //         result += to_string(i) + " ";
    //     }
    // }
    // cout << "\n";
    // cout << count << "\n";
    // cout << result;
}   