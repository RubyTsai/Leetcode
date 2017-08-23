class Solution {
public:
    int findMinStep(string board, string hand) {
        this->board = move(board);
        bsize = this->board.size();
        
        int handMap[26] = {0};
        for (auto c: hand)
            handMap[c-'A']++;
        
        int dp[20][20][20];
        for (int i = 0; i < 20; i++)
            for (int j = 0; j <20; j++) 
                for (int k = 0; k <20; k++)
                    dp[i][j][k] = 1000;
        int ret = helper(0, bsize-1, 0, handMap, dp);
        return ret > hand.size()? -1: ret;
    }
private:
    string board;
    int bsize, bsquare;
    int helper (int start, int end, int same, int hand[26], int dp[20][20][20]) {
        if (start > end) return 0;
        if (dp[start][end][same] != 1000) return dp[start][end][same];
        
        while (start < end && board[start] == board[start+1]) {
            start++;
            same++;
        }
        
        //hand[board[start]] - (3-same-1) >= 0
        if (same < 2 && hand[board[start]- 'A'] >= (2-same)) {
            hand[board[start]- 'A'] -= 2-same; 
            dp[start][end][same] = 2-same + helper(start+1, end, 0, hand, dp);
            hand[board[start]- 'A'] += 2-same; 
        }
        if (same > 1) dp[start][end][same] = helper(start+1, end, 0, hand, dp);
        for (int i = start + 1; i <= end; i++) {
            if (board[i] == board[start]) {
                dp[start][end][same] = min(dp[start][end][same], 
                                           helper(start+1, i-1, 0, hand, dp) + 
                                           helper(i, end, same+1, hand, dp));
            }
        }
        return dp[start][end][same];       
    }
};
