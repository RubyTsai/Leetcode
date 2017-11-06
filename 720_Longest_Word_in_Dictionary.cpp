class Solution {
public:
    string longestWord(vector<string>& words) {   
        string ans;
        sort(words.begin(), words.end(), [&](const string& a, const string& b){ return (a.size() < b.size());});
        dicSet.insert(words.begin(), words.end());
        for (auto& w: words) {
            if (w.size() == 1) {
                if (w.size() > ans.size()) ans = w;
                else if (w.size() == ans.size() && w < ans) ans = w;
            }
            else if (helper(w)) {
                if (w.size() > ans.size()) ans = w;
                else if (w.size() == ans.size() && w < ans) ans = w;
            } 
        }
        return ans;
    }
private:
    unordered_set<string> dicSet;
    unordered_set<string> builtSet;
    unordered_set<string> failSet;
    bool helper(string s) {
        if (builtSet.count(s)) return true;
        if (failSet.count(s)) return false;
        
        string prefix = s.substr(0, s.size()-1);
        string suffix = s.substr(s.size()-1);
        if (prefix.size() == 1) {
            if (dicSet.count(prefix) || dicSet.count(suffix)) {
                builtSet.insert(s);
                return true;
            }
            else {
                failSet.insert(s);
                return false;
            }
        }
        
        if (builtSet.count(prefix)/* && dicSet.count(suffix)*/) {
            builtSet.insert(s);
            return true;
        }
        else {
            prefix = s.substr(1, s.size()-1);
            //suffix = s.substr(0, 1);
            if (builtSet.count(prefix)/* && dicSet.count(suffix)*/) {
                builtSet.insert(s);
                return true;
            }
            else {
                failSet.insert(s);
                return false;
            }
        }
    }
};
