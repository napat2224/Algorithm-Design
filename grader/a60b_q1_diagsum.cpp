#include <iostream>
#include <vector>
using namespace std;
/*
4 
1 2 3 4
-2 -5 2 -5
6 3 -7 1 
3 -2 7 -9

2
1 2
3 4

3 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
int n;
vector<vector<int>> a;

int mss(vector<int> &c, int start, int stop, vector<int> &s){
    if(start == stop) return c[start];
    int m = (start+stop) /2;

    int r1 = mss(c,start,m,s);
    int r2 = mss(c,m+1,stop,s);

    int r3 = c[start];
    // cout << r3 << " <- r3\n";
    for(int p=start; p<=m; p++){
        for(int q=m; q<=stop; q++){
            int sum = s[q] - s[p-1];
            // cout << s[q] << "("<<q<<") - " << s[p-1] << "("<<p-1<<") = " << sum <<"\n";
            if(sum > r3) r3 = sum;
            // cout << r3 << "<- r3\n";
        }
    }
    return max(r3,max(r1,r2));
}

int main(){
    cin >> n;
    a.resize(n+1, vector<int>(n+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0) a[i][j] = 0;
            else cin >> a[i][j];
        }
    }
    int mmax = a[1][1];
    for(int i=0; i<n; i++){
        vector<int> c,s,c2,s2;
        c2.push_back(0);
        s2.push_back(0);
        c.push_back(0);
        s.push_back(0);
        int sum = 0;
        int sum2 = 0;
        if(i == 0){
            for(int j=1; j<=n; j++){
                sum += a[j][j];
                c.push_back(a[j][j]);
                s.push_back(sum);
                // cout << "push c: " << a[j][j] <<"\n";
                // cout << "push s: " << sum << "\n";
            }
            int tmp = mss(c,1,n,s);
            mmax = (tmp>mmax)? tmp:mmax;
            // cout << tmp << " <- tmp\n";    
        }else{
            for(int j=1; j<=n-i; j++){
                sum += a[j][i+j];
                c.push_back(a[j][i+j]);
                s.push_back(sum);                
                sum2 += a[j+i][j];
                c2.push_back(a[j+i][j]);
                s2.push_back(sum2);
                // cout << "push c: " << a[j][j+i] <<"\n";
                // cout << "push s: " << sum << "\n";
                // cout << "push c2: " << a[j+i][j] <<"\n";
                // cout << "push s2: " << sum2 << "\n";
            }
            int tmp1 = mss(c,1,n-i,s);
            mmax = (tmp1>mmax)? tmp1:mmax;                
            int tmp2 = mss(c2,1,n-i,s2);
            mmax = (tmp2>mmax)? tmp2:mmax;  
            // cout << tmp1 << " <-tmp1 \n";    
            // cout << tmp2 << " <-tmp2\n";  
        }
    }
    cout << mmax;
}