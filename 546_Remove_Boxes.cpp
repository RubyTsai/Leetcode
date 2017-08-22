class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        // 3 3 3 .... 3 ...
        int dp[100][100][100] = {0};
        return helper(boxes, dp, 0, boxes.size()-1, 0);
    }    
private:
    int helper(vector<int>& b, int (&dp)[100][100][100], int start, int end, int same) {
        if (start > end) return 0;
        if (dp[start][end][same] != 0) return dp[start][end][same];
        
        while (start < end && b[start+1] == b[start]) {
            same++;
            start++;
        } // same = 2, start -> 2
        // [3 3 3] [.... 3 ...]
        dp[start][end][same] = (same+1) * (same+1) + helper(b ,dp, start+1, end, 0);
        for (int i = start+1; i <= end; i++)
            if (b[start] == b[i]) {
                dp[start][end][same] = max(dp[start][end][same], 
                                          //  3 3 3 [....] [3 ...] // 後面的 3 與前面連續的 3 合併在一起
                                          helper(b, dp, start+1, i-1, 0) + helper(b, dp, i, end, same+1));
            }
        return dp[start][end][same];
    }
};
