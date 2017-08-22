class Solution {
public:
    int findMinStep(string board, string hand) {
        bsize = board.size();
        bsquare = bsize*bsize;
        unordered_map<char, int> handMap;
        for (auto c: hand)
            handMap[c]++;
        helper(0, bsize-1, 0, board, hand, dp);
    }
private:
    int bsize, bsquare;
    int helper (int start, int end, int same, string board, string hand, int dp[][][]) {
        if (start > end) return 0; // ?
        if (dp[start][end][same] != bsquare) return dp[start][end][same];
        
        while (start < end && string[start] == string[start+1]) {
            start++;
            same++;
        }
        int cost = 
        if (same+1 >= 3) dp[start][end][same] = 0;
    }

};
