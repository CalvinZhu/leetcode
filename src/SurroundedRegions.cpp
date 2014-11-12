//http://www.cnblogs.com/easonliu/p/3680630.html
class Solution {
public:
    void fill(vector<vector<char> > &board, int x, int y) {
        board[x][y] = '.';
        if (y + 1 < board[0].size() - 1 && board[x][y+1] == 'O')
            fill(board, x, y + 1); //right
        if (x + 1 < board.size() - 1 && board[x+1][y] == 'O')
            fill(board, x + 1, y); //down
        if (y - 1 > 0 && board[x][y-1] == 'O')
            fill(board, x, y - 1); //left
        if (x - 1 > 0 && board[x-1][y] == 'O')
            fill(board, x - 1, y); //up
    }
    
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3) return;
        if (board[0].size() < 3) return;
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[0][j] == 'O')
                fill(board, 0, j);
            if (board[board.size()-1][j] == 'O')
                fill(board, board.size() - 1, j);
        }
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O')
                fill(board, i, 0);
            if (board[i][board[0].size()-1] == 'O')
                fill(board, i, board[0].size() - 1);
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
