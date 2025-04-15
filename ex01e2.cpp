#include <iostream>
#include <vector>
using namespace std;

vector<int> S;

/*
    ! Kadane's Algorithm at line 90
test : 
15 1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4
-> 10
8 -1 -2 -2 -2 -2 -2 -2 -1
-> -1
*/

int mss1(vector<int> &A){
    int max = A[0];
    for(int i=0; i<A.size(); i++){
        int temp = A[i];
        for(int j=i+1; j<A.size();j++){
            if(temp>max) max = temp;
            temp += A[j];
        }
    }
    return max;
}

int mss_prefix_sum(vector<int> &A){
    vector<int> S;
    S.push_back(0);
    int sum = 0;
    for(int i=0; i<A.size();i++){
        sum+=A[i];
        S.push_back(sum);
    }

    int max = A[0];
    for(int i=1;i<=A.size();i++){
        for(int j=i; j<=A.size(); j++){
            // cout << "j: " << j << " i: " << i <<"\n";
            sum = S[j] - S[i-1];
            if(sum>max) max = sum;
        }
    }
    return max;
}

//the r3 is n^2
int mss_dav_v1(vector<int> &A, int start, int stop, vector<int> &S){
    if(start == stop) return S[stop] - S[start-1];
    int m = (start+stop)/2;

    int r1 = mss_dav_v1(A, start, m, S);
    int r2 = mss_dav_v1(A, m+1, stop, S);

    int r3 = S[stop]-S[start];
    int temp;
    for(int i=start; i<=m; i++){
        for(int j=m; j<=stop; j++){
            temp = S[j]-S[i-1];
            if(temp > r3) r3 = temp;
        }
    }
    return max(r3,max(r1,r2));
}

// nlogn better r3 (actual work) O(n)
int get_sum(vector<int> &S,int a,int b){
    return S[b] - S[a-1];
}
int mss_dav_v2(vector<int> &A, int start, int stop, vector<int> &S){
    if(start == stop) return S[stop] - S[start-1];
    int m = (start+stop)/2;

    int r1 = mss_dav_v2(A, start, m, S);
    int r2 = mss_dav_v2(A, m+1, stop, S);

    // B[start...m][m]
    int max_sum_left = get_sum(S,m,m);
    for(int i=start; i<=m;i++){
        max_sum_left = max(max_sum_left,get_sum(S,i,m));
    }
    // B[m+1...stop][stop ]
    int max_sum_right = get_sum(S,m+1,m+1);
    for(int i=m+1; i<=stop;i++){
        max_sum_right = max(max_sum_right,get_sum(S,m+1,i));
    }
    int r3 = max_sum_left + max_sum_right;
    return max(r3,max(r1,r2));
}

// ! kadane ไปดูใหม่ ไม่ไหวละ

int max_suffix(vector<int> &A, int stop, vector<int>& table, vector<int> &done){
    //max sum 1,2,3,... -> stop
    if(stop == 1) return A[1];
    if(done[stop]) return table[stop];
    table[stop] = max(A[stop],A[stop]+max_suffix(A,stop-1));
    return 
}

int mss_kadane1(vector<int> &A, int stop){
    if( stop == 1) return A[1];
    int r1 = mss_kadane1(A,stop-1);
    int r2 = A[stop];
    int r3 = max_suffix(A,stop-1) + A[stop];
    return max(max(r1,r2),r3);
}

int main(){
    int n;
    cin >> n;
    vector<int> A;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    // vector<int> S;
    S.push_back(0);
    int sum = 0;
    for(int i=0; i<A.size();i++){
        sum+=A[i];
        S.push_back(sum);
    }
    // cout << mss_dav_v2(A,1,A.size(),S);
    cout << mss_kadane1(A,A.size()-1);
}