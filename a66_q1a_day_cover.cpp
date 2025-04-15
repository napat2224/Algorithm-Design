#include <iostream>
#include <vector>
#include <set>

using namespace std;

int nday,nstudent,mymin;

int recur(vector<vector<int>> &v,int student, int count,set<int> days){
    if(count >= mymin) return mymin;
    int a = days.size();
    if(v[student].size() == 0) return mymin;
    for(auto x: v[student]){
        days.insert(x);
    }
    if(days.size() == nday) {
        if(count < mymin) mymin = count;
        // cout << "change to " << count << "\n";
        return mymin;
    }
    if(days.size() == a) return mymin;


    for(int i=student; i<nstudent;i++){
        mymin = recur(v,i,count+1,days);
    }
    return mymin;
}


int main(){
    // int nday, nstudent;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> nday >> nstudent;

    vector<vector<int>> V(nstudent);
    for(int i=0; i<nstudent; i++){
        int temp;
        cin >> temp;
        for(int j=0;j<temp;j++){
            int temp2;
            cin >> temp2;
            V[i].push_back(temp2);
        }
    }
    set<int> s;
    mymin = nstudent+1;
    mymin = recur(V,0,1,s);
    for(int i=1; i<nstudent; i++){
        mymin = min(mymin,recur(V,i,1,s));
    }
    cout << mymin;
}