#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for (int stone = 1; stone<=n;stone++){
        for (int group=1; group<=k; group++){

            if (group == 1) {
                dp[stone][group] = 1;
            }
            else if (group > stone) {
                dp[stone][group] = 0;
            } else {
                // create new group
                int tmp1 = dp[stone-1][group-1];
                // put in every existing group
                int tmp2 = (dp[stone-1][group] * group)%1997;
                dp[stone][group] = (tmp1+tmp2)%1997;
            }

        }
    }
    cout << dp[n][k];
}