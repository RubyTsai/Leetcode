/* -------------------------------------------------------------------
Given a non-empty 2D array grid of 0's and 1's, 
an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:                                           Example 2:
11000                                                11011
11000                                                10000
00011                                                00001
00011                                                11011
Given the above grid map, return 1.                  Given the above grid map, return 3.

Notice that:
11    and   1
1          11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
---------------------------------------------------------------------*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        row = grid.size();
        if (0 == row) return 0;
        col = grid[0].size();
        this->grid = grid;
        vector<vector<int>> vec;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (1 == this->grid[i][j]) {
                    vector<int> tmp(2, 0);
                    i0 = i; j0 = j;
                    numDistinctIslands(i, j, true, tmp);
                    vec.push_back(tmp);
                }
            }
        set<vector<int>> s(vec.begin(), vec.end());
        return s.size();
    }
private:
    int row, col;
    int i0, j0;
    vector<vector<int>> grid;
    void numDistinctIslands(int i, int j, bool ori, vector<int>& tmp) {
        if (i < 0 || j < 0 || i >= row || j >= col) return;
        if (0 == grid[i][j]) return;
        
        grid[i][j] = 0;
        if (!ori) {
            tmp.emplace_back(i-i0);
            tmp.emplace_back(j-j0);
        }
        else ori = false;
        
        numDistinctIslands(i-1, j, ori, tmp);
        numDistinctIslands(i, j-1, ori, tmp);
        numDistinctIslands(i+1, j, ori, tmp);
        numDistinctIslands(i, j+1, ori, tmp);
    }
};
