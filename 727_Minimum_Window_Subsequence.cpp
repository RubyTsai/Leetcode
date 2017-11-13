/* ----------------------------------------------------------------------------------------------------
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
If there is no such window in S that covers all characters in T, return the empty string "". 
If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example:
  Input: 
    S = "abcdebdde", T = "bde"
  Output: "bcde"
  Explanation: 
    "bcde" is the answer because it occurs before "bdde" which has the same length.
    "deb" is not a smaller window because the elements of T in the window must occur in order.

Note:
1. All the strings in the input will only contain lowercase letters.
2. The length of S will be in the range [1, 20000].
3. The length of T will be in the range [1, 100].
---------------------------------------------------------------------------------------------------- */
class Solution {
public:
    string minWindow(string S, string T) {
        int tsize = T.size(), minSize = INT_MAX;
        vector<vector<int>> table(tsize);
        vector<int> tableIt(tsize, 0);
        vector<int> pos(tsize, 0);

        char c;
        for (int i = 0; i < tsize; i++) {
            c = T[i]; 
            int find = S.find(c);
            while (find != string::npos) {
                table[i].emplace_back(find);
                find = S.find(c, find+1);
            }
            if (table[i].empty()) return "";
        }
        
        string ans = "";
        for (int i = 0; i < table[0].size(); i++) {
            pos[0] = table[0][i]; 
            for (int j = 1; j < tsize; j++) {
                while (tableIt[j] < table[j].size() &&
                       table[j][tableIt[j]] <= pos[j-1]) tableIt[j]++;
                if (tableIt[j] == table[j].size()) return ans;
                else pos[j] = table[j][tableIt[j]];
            }
            if (pos[tsize-1]-pos[0]+1 < minSize) {
                minSize = pos[tsize-1]-pos[0]+1;
                ans.clear();
                ans = S.substr(pos[0], minSize);
            }
        }
        return ans;
    }
};
//--------------------------------------------------------- 以下方法會 time out
class Solution {
public:
    string minWindow(string S, string T) {
        string ans = "";
        int ssize = S.size(), tsize = T.size();
        
        int find = S.find(T[0]);        
        while (find != string::npos) {
            int si = find;
            int sj = si+1, ti = 1;
            for (; sj < ssize && ti < tsize; sj++) {
                if (S[sj] == T[ti]) ti++;
            }
            if (ti == tsize) {
                string tmp = S.substr(si, sj-si);
                if (ans.empty() || ans.size() > sj-si) {
                    ans.clear();
                    ans = move(tmp);
                }
                find = S.find(T[0], si+1);
            }
            else break;
        }
        return ans;
    }
};
