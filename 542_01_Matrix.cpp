class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> res(row, vector<int>(col, row * col));
        // two passes, first forward then backward
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (0 == matrix[i][j]) res[i][j] = 0;
                else {
                    if (i && res[i][j] > res[i-1][j] + 1) // look up
                        res[i][j] = res[i-1][j] + 1;
                    if (j && res[i][j] > res[i][j-1] + 1) // look left
                        res[i][j] = res[i][j-1] + 1;
                }                                                  
            }
        for (int i = row - 1; i >= 0; i--)
            for (int j = col - 1; j >= 0; j--) {                
                if (i != row - 1 && res[i][j] > res[i+1][j] + 1) // look down
                    res[i][j] = res[i+1][j] + 1;
                if (j != col - 1 && res[i][j] > res[i][j+1] + 1) // look right
                    res[i][j] = res[i][j+1] + 1;                                                                  
            }
        return res;
    }
};
