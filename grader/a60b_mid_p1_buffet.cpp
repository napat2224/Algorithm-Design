#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
test1:
3 0 10
1 3 4
out: 3 (1 3 4)

test2:
5 1 10
1 2 3 5 6
out: 2 (2, 5)

test3:
10 5 10
1 10 9 2 3 4 8 7 5 6
out: 1 (5)
*/

int f, w, n;
vector<int> sol;
vector<int> food;
vector<bool> used;
// void buffet(int idx,int idxf, int lamp) {
//     if(idx < n && idxf < f) {
//         sol[idx] = 1;
//         buffet(idx+1+w, idxf+1, lamp+1);
//         sol[idx] = 0;
//         buffet(idx+1, idxf, lamp);
//     } else {

//     }
// }

int main(){
    cin >> f >> w >> n;
    food.resize(f);
    sol.resize(n);
    used.resize(f);
    for(int i=0; i<f; i++){
        cin >> food[i];
        food[i]-=1; //make first index 0
    }
    sort(food.begin(),food.end());
    int curlight = food[0]+w+w;
    int count = 1;
    for(int i=1; i<f; i++){
        if(curlight>=food[i]) continue;
        curlight = food[i]+w+w;
        count++;
    }
    cout << count;
}