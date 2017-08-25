bool cmpLen(const string& a, const string& b) { 
    return (a.size() < b.size()) ;
}
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmpLen);
        
        int i= 0;
        while(words[i].size() == 0) ++i;
        minSize = words[i].size();
        unordered_set<string> hashset(words.begin(), words.begin()+1);
        
        vector<string> ret;        
        for (; i < words.size(); i++) {
            if (words[i] == words[i-1]) continue;
            if (words[i].size() > minSize) {
                if (isCompose(words[i], 0, words[i].size()-1, hashset))
                    ret.push_back(words[i]);
            }
            hashset.insert(words[i]);
        }
        return ret;
    }
private:
    int minSize;
    bool isCompose(string& w, int begin, int end, unordered_set<string>& hashset) {
        if (begin > end) return true;
        for (int i = begin; i <= (end-minSize+1); i++) {
            for (int j = i; j <= end; j++)
                if (hashset.find(w.substr(i, j-i+1)) != hashset.end()) {
                    if (isCompose(w, j+1, end, hashset)) return true;
                } 
        }
        return false;
    }

};
