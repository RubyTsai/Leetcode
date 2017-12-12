class Solution {
public:
/* There're 3 possibilities to satisfy one edit distance apart: 
 * 
 * 1) Replace 1 char:
 	  s: a B c
 	  t: a D c
 * 2) Delete 1 char from s: 
	  s: a D  b c
	  t: a    b c
 * 3) Delete 1 char from t
	  s: a   b c
	  t: a D b c                                                  */
    bool isOneEditDistance(string s, string t) {
        int ss = s.size(), ts = t.size();
        if (ss == 0 && ts == 0) return false;
        for (int i = 0; i < min(ss, ts); i++) {
            if (s[i] != t[i]) {
                if (ss == ts) // case 1
                    return s.substr(i+1) == t.substr(i+1);                
                else if (ss > ts) // case 2
                    return s.substr(i+1) == t.substr(i);
                else // case 3
                    return s.substr(i) == t.substr(i+1);
            }
        }
        //All previous chars are the same, the only possibility is deleting the end char in the longer one of s and t 
        int diff = ss >= ts? ss-ts: ts-ss;
        return diff == 1;
    }
};
