class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> results;
        if ((rows = matrix.size()) == 0 || (cols = matrix[0].size()) == 0) 
            return results;
        visit.resize(rows, vector<int>(cols, 0));
        // 從所有臨海的地方出發, Pacific 出發的為 1, Atlantic 出發的為 2 
        for (int j = 0; j < cols; j++) {
            helper(0, j, 1, matrix);
            helper(rows-1, j, 2, matrix);
        }
        for (int i = 0; i < rows; i++) {
            helper(i, 0, 1, matrix);
            helper(i, cols-1, 2, matrix);
        }
        // 檢查 visit 的結果，兩個海洋都可到達的話，結果會是 3 (1 & 2 的結果)
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (visit[i][j] == 3) results.push_back({i, j});
        return results;
    }
private:
    int rows, cols;
    vector<vector<int>> visit;
    // di[4], dj[4] 分別對應到: up, down, left, right
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    void helper(int i, int j, int from, vector<vector<int>>& m) {
        visit[i][j] |= from;        
        int nexti, nextj;
        for (int k = 0; k < 4; k++) {
            nexti = i + di[k];
            nextj = j + dj[k];
            if (nexti >= 0 && nexti < rows && nextj >= 0 && nextj < cols &&
                m[nexti][nextj] >= m[i][j] && (visit[nexti][nextj] & from) == 0)
                helper(nexti, nextj, from, m);
        }        
    }
};
/*----------------
1、分别從每個海洋邊緣（矩陣的四個邊) 開始出發，一步步的探訪，如果鄰居比自己高，則表示可以到達 (反過來即是水流可以從鄰居流到自己)。
可以走到的點，就在 visit 裡面標記下來，看是從哪個海洋來的。
2、最後檢查 visit 的結果，從兩個海洋都可到達某個點，該點的結果會是 3
-----------------*/
