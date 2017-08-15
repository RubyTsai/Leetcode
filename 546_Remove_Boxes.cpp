class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int bsize = boxes.size();
        if (bsize == 0) return 0;
        vector<vector<int>> dp(bsize, vector<int>(bsize, 0));
        for (int i = 0; i < bsize; i++)
            dp[i][i] = 1;
        
        for (int length = 2; length <= bsize; length++) {
            for (int i = 0; i <= bsize-length; i++) {
                int j = i + length - 1;
                for (int k = i; k <= j; k++) {
                    int same = 1;
                    while (k+1 <= j && boxes[k+1] == boxes[k]) {
                        k++;
                        same++;
                    }
                    points = same*same;
                    if (same == length) dp[i][j] = points;
                    else {
                        int seg0 = (k-1 < i)? 0: dp[i][k-1];
                        int seg2 = (k+1 > j)? 0: dp[k+1][j];
                        dp[i][j] = min(dp[i][j], seg0 + points + seg2);
                    }
                }
            }
        }
    }
};
