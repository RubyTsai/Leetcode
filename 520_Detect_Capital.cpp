class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (auto& c: word) 
            if (c - 'A' < 26) count++;
        return (count == 0 || count == word.size() || (count == 1 && word[0] - 'A' < 26));
    }
};
/*
class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.size();
        if (word.empty() || size == 1) return true;
        
        char c = word[0];        
        if (c - 'A' < 26) {
            bool allBig = false, big;
            c = word[1];
            if (c - 'A' < 26) allBig = true;
            for (int i = 2; i < size; i++) {
                c = word[i];
                big = (c - 'A' < 26)? true: false;
                if ((allBig && !big) || (!allBig && big)) return false;
            }
        }
        else {
            for (int i = 1; i < size; i++) {
                c = word[i];
                if (c - 'A' < 26) return false;
            }
        }
        return true;   
    }
};*/
