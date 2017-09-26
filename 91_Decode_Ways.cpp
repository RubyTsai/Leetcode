class Solution {
public:
    int numDecodings(string s) {
        int sSize = s.size();
        if (0 == sSize) return 0;
        vector<int> dp(sSize, 1);
        
        if (s[0] == '0') return 0;
        
        // decide dp[1]
        if (sSize > 1 && (s[0] == '1' || 
                         (s[0] == '2' && (s[1] - '0') < 7))) dp[1]++;
        if (s[1] == '0') dp[1]--;
        
        for (int i = 2; i < sSize; i++) {
            if(s[i] == '0') {
                if((s[i-1] - '0') > 2) return 0;
                else dp[i] = 0;
            }
            else dp[i] = dp[i-1];
            
            if (s[i-1] == '1' ||
               (s[i-1] == '2' && (s[i] - '0') < 7)) dp[i] += dp[i-2];
        }
        return dp[sSize-1];
    }
};
