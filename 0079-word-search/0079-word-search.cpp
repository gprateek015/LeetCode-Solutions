class Solution {
    bool solve(vector<vector<char>> &board, string &word, int i, int j, int c) {
        if(c >= word.size()) return 1;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return 0;

        if(board[i][j] != word[c]) 
            return 0;
        char ch = board[i][j];
        board[i][j] = '.';
        bool ans = 0;
        ans |= solve(board, word, i+1, j, c+1);
        ans |= solve(board, word, i, j+1, c+1);
        ans |= solve(board, word, i-1, j, c+1);
        ans |= solve(board, word, i, j-1, c+1);
        board[i][j] = ch;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(solve(board, word, i, j, 0))
                    return 1;
            }
        }
        return 0;
    }
};