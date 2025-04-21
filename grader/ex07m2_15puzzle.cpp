#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> goal = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

class Board {
    public:
        vector<vector<int>> b;
        vector<int> move;
        int r,c; //empty space
        int heuristic_value;
        int heuristic_mode;
        // 0 -> # of misplace pieces
        // 1 -> sum of distance of misplace pieces

        Board() {
            b = goal;
            r = 3;
            c = 3;
            heuristic_mode = 0;
        }

        bool is_goal() {
            return b == goal;
        }
        //0,1,2,3 -> up, down, left, right
        //can go -> return true, cannot -> false and do nothing
        bool do_move(int direction) {
            if(direction == 0) {
                if (r==0) return false;
                b[r][c] = b[r-1][c];
                b[r-1][c] = 0;
                r--;
            } else if (direction == 1) {
                if (r==3) return false;
                b[r][c] = b[r+1][c];
                b[r+1][c] = 0;
                r++;
            } else if (direction == 2) {
                if (c==0) return false;
                b[r][c] = b[r][c-1];
                b[r][c-1] = 0;
                c--;
            } else if(direction ==3) {
                if (c==3) return false;
                b[r][c] = b[r][c+1];
                b[r][c+1] = 0;
                c++;
            }
            move.push_back(direction);

            if(heuristic_mode == 0) heuristic_value = heuristic0();
            else heuristic_value = heuristic1();

            return true;
        }

        int heuristic0(){
            return 0;
        }

        int heuristic1(){
            return 1;
        }

        //better use unorder set but in this case just set 
        bool dupcheck(){
            return false;
        }

        bool operator<(const Board& other) const {
            return this->b < other.b;
        }

        void print(){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    
                }
            }
        }

};

vector<vector<int>> board(4,vector<int> (4));

int main(){  
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cin >> board[i][j];
        }
    }

}