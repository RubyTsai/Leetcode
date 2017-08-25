bool cmpLen(const string& a, const string& b) { 
    return (a.size() < b.size()) ;
}
class Solution {
public:
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
