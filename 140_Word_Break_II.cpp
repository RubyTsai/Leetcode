class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

    }
    vector<string> helper (string s, unordered_set<string>& dict, ) {
        vector<string> ret;
        for (int len = 1; len <= s.size(); len++) {
            string sub = s.substr(0, len);
            if (dict.find(sub) != dict.end()) {
                vector<string> append = helper(s.substr(len), );
                ret.push_back(sub + " " + );
            }
        }
    }
};
