class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> hash(9);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9;j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                int idx = ((i/3) * 3) + (j/3);
                hash[idx].push_back(val);
            }
        }


        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                if(checkDuplicateRowAndCol(i, j, board)) return false;
                int curIdx = ((i/3) * 3) + (j/3);
                int curVal = board[i][j] - '0';
                int cnt = 0; 
                for(auto val: hash[curIdx]) {
                    if(curVal == val) cnt+=1;
                }
                if(cnt > 1) return false;
            }
        }
        return true;
    }

    bool checkDuplicateRowAndCol(int i, int j, vector<vector<char>>& board) {
        int curVal = board[i][j] - '0';

        // checkRow 
        for(int rowCheck = j+1; rowCheck <= 8; rowCheck++) {
            if(board[i][rowCheck] == '.') continue; 
            int curBoxVal = board[i][rowCheck] - '0';
            if(curBoxVal == curVal) return true;
        }


        // checkCol 
        for(int colCheck = i+1; colCheck<=8; colCheck++) {
             if(board[colCheck][j] == '.') continue; 
             int curBoxVal = board[colCheck][j] - '0';
             if(curBoxVal == curVal) return true;
        }
        return false;
    }
};
