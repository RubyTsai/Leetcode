class Solution {
public:
    int findMinStep(string board, string hand) {
        this->board = move(board);
        bsize = this->board.size();
        bsquare = bsize*bsize;
        unordered_map<char, int> handMap;
        for (auto c: hand)
            handMap[c]++;
        int dp[20][20][20] = {bsquare};
        int ret = helper(0, bsize-1, 0, handMap, dp);
        return ret == bsquare? -1: ret;
    }
private:
    string board;
    int bsize, bsquare;
    int helper (int start, int end, int same, unordered_map<char, int>& hand, int dp[20][20][20]) {
        if (start > end) return 0; // ?
        if (dp[start][end][same] != bsquare) return dp[start][end][same];
        
        while (start < end && board[start] == board[start+1]) {
            start++;
            same++;
        }
        
        unordered_map<char, int> newHand(hand);
        //hand[board[start]] - (3-same-1) >= 0
        if (same < 2 && hand[board[start]] >= (2-same)) {
            hand[board[start]] -= 2-same; 
            dp[start][end][same] = 2-same + helper(start+1, end, 0, hand, dp);
            hand[board[start]] += 2-same; 
        }
        if (same > 1) dp[start][end][same] = helper(start+1, end, 0, hand, dp);
        for (int i = start; i <= end; i++) {
            if (board[i] == board[start]) {
                dp[start][end][same] = min(dp[start][end][same], 
                                           helper(start+1, i-1, 0, hand, dp) + 
                                           helper(i, end, same+1, hand, dp));
            }
        }
        return dp[start][end][same];       
    }
};
