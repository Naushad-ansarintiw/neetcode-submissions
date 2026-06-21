class Solution {
public:
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};

    bool isWordThere(int r, int c, int idx,
                     vector<vector<char>>& board,
                     string& word,
                     int n, int m,
                     vector<vector<int>>& vis) {

        // matched entire word
        if (idx == word.size()) return true;

        // out of bounds
        if (r < 0 || c < 0 || r >= n || c >= m)
            return false;

        // already visited
        if (vis[r][c])
            return false;

        // character mismatch
        if (board[r][c] != word[idx])
            return false;

        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isWordThere(nr, nc, idx + 1, board, word, n, m, vis)) {
                return true;
            }
        }

        vis[r][c] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));

                    if (isWordThere(i, j, 0, board, word, n, m, vis))
                        return true;
                }
            }
        }

        return false;
    }
};