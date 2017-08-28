class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> mdp;
        return helper(s, dict, mdp);
    }
private:
    vector<string> helper(string s, unordered_set<string>& dict, 
                          unordered_map<string, vector<string>>& mdp) {
        if (mdp.count(s)) return mdp[s]; //take from memory
            
        vector<string> ret;
        if (dict.count(s)) ret.push_back(s);//原字串本身也可以在 dict 中找到，則直接放入 result 中 
        
        for (int len = 1; len < s.size(); len++) {
            string left = s.substr(0, len);
            if (dict.count(left)) {
                vector<string> suffixes= helper(s.substr(len), dict, mdp);
                for (auto& suffix: suffixes)
                    ret.push_back(move(left + " " + suffix));
            }
        }
        mdp[s] = ret;
        return ret;
    }
};
