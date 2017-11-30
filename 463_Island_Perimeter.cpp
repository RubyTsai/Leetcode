class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) 
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) ans += helper(i, j, grid);
            }
        return ans;
    }
private:
    int row, col;
    int helper(int i, int j, vector<vector<int>>& grid) {        
        int ans = 0;
        grid[i][j] = -1;
        if (i == 0) ans++;
        if (i == row-1) ans++;
        if (j == 0) ans++;
        if (j == col-1) ans++;
        
        if (i > 0) {
            if (grid[i-1][j] == 1) ans += helper(i-1, j, grid);
            else if (grid[i-1][j] == 0) ans++; 
        }
        if (i+1 < row) {
            if (grid[i+1][j] == 1) ans += helper(i+1, j, grid);
            else if (grid[i+1][j] == 0) ans++;
        }
        if (j > 0) {
            if (grid[i][j-1] == 1) ans += helper(i, j-1, grid);
            else if (grid[i][j-1] == 0) ans++; 
        }
        if (j+1 < col) {
            if (grid[i][j+1] == 1) ans += helper(i, j+1, grid);
            else if (grid[i][j+1] == 0) ans++;
        }
        return ans;
    }
};
