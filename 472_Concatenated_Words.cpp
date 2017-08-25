bool cmpLen(const string& a, const string& b) { 
    return (a.size() < b.size()) ;
}
class Solution {
public:
    // 此版本可 pass leetcode，但是若 words 有重複的字，則會有錯
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        sort(words.begin(), words.end(), cmpLen);
        
        int i= 0;
        unordered_set<string> dict; 
        while(words[i].size() == 0) ++i;               
        for (; i < words.size(); i++) {
            if (helper(words[i], dict))
                ret.push_back(words[i]);          
            dict.insert(words[i]);
        }
        return ret;
    }
private:
    int minSize;
    bool helper(string& w, unordered_set<string>& dict) {
        if (dict.empty()) return false;
        vector<bool> dp(w.size()+1, false);
        dp[0] = true;
        
        for (int len = 1; len <= w.size(); len++) {
            for (int j = len-1; j >= 0; j--) {
                if (dp[j] && dict.find(w.substr(j, len-j)) != dict.end()) {
                    dp[len] = true;
                    break;
                }
            }                
        }
        return dp[w.size()];
    }
};

/* -------------------------

若將 helper 改成這樣，就可以解決 input (words) 有重複的情況
(關鍵在於不要把整個 w 丟進去 dict 裡面去找)
 
    bool helper(string& w, unordered_set<string>& dict) {
        if (dict.empty()) return false;
        vector<bool> dp(w.size()+1, false);
        dp[0] = true;
        
        for (int len = 1; len < w.size(); len++) {
            for (int j = len-1; j >= 0; j--) {
                if (dp[j] && dict.find(w.substr(j, len-j)) != dict.end()) {
                    dp[len] = true;
                    break;
                }
            }                
        }
        
        for (int j = w.size() - 1; j > 0; j--) {
            if (dp[j] && dict.find(w.substr(j, w.size()-j)) != dict.end()) {
                dp[w.size()] = true;
                break;
            }
        }               
        return dp[w.size()];
    }
----------------------------*/
