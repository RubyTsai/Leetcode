class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0], col = click[1];
        if (board[row][col] == 'M') { // Mine
            board[row][col] = 'X';
        }                    
        else {// Empty
            // Get number of mines first.
            int brows = board.size(), bcols = board[0].size();
            int count = 0;
            for (int i = (row == 0)? 0: -1; i < 2 ; i++) {
                if (row + i >= brows) break;
                for (int j = (col == 0)? 0: -1; j < 2; j++) {
                    if (i == 0 && j == 0) continue;
                    if (col + j >= bcols) break;
                    if (board[row+i][col+j] == 'M' ||
                        board[row+i][col+j] == 'X')
                        count++;
                }
            }
            if (count > 0) { // If it is not a 'B', stop further DFS.
                board[row][col] = '0'+ count;
            }
            else { // Continue BFS to adjacent cells.
                board[row][col] = 'B';
                for (int i = (row == 0)? 0: -1; i < 2 ; i++) {
                    if (row + i >= brows) break;
                    for (int j = (col == 0)? 0: -1; j < 2; j++) {  
                        if (i == 0 && j == 0) continue;                        
                        if (col + j >= bcols) break;
                        if (board[row+i][col+j] == 'E') {
                            vector<int> next = {row+i, col+j};
                            updateBoard(board, next);
                        }
                    }
                }                
            }       
        }
        return board;    
    }
};
