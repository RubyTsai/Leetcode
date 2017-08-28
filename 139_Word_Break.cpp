class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        dp[0] = dict.count(s.substr(0, 1)) > 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (dict.count(s.substr(0, i+1))) {
                dp[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) 
                if (dp[j] && dict.count(s.substr(j+1, i-j))) {
                    dp[i] = true;
                    break;
                }           
        }
        return dp[s.size()-1];
    }
};
/*-----------------------------------------------
dp[i] 為第 i 個位置的這個字串之前(包含 i)可否被拆解
abc 可視為：[abc], [a][bc], [ab][c]
檢查 [abc] 的方式於 line 9 ~ line 12,
[a][bc], [ab][c] 則於 line 13 ~ line 17
[a][bc]: 檢查 dp[0] 與子字串 bc
[ab][c]: 檢查 dp[1] 與子字串 c
------------------------------------------------*/
