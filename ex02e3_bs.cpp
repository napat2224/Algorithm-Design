#include <iostream>

using namespace std;

int main(){
    int n, m;
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    int a[n];
    for(int i = 0; i<n ;i++){
        int tmp;
        scanf("%d", &tmp);
        // cin >> tmp;
        a[i] = tmp;
    }
    for(int i=0; i<m; i++){
        int tmp;
        // cin >> tmp;
        scanf("%d", &tmp);
        // bool found = false;
        int max = 0;
        for(int j=0; j<n; j++){
            if(a[j] <= tmp) {
                max = (a[j]>max)? a[j]:max;
                // found = true;
            }
        }
        // if(!found) cout << "-1\n";
        if(max == 0) printf("-1\n");
        // else cout << max << "\n";
        else printf("%d\n",max);
        
    }
}