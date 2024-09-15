class Solution {
public:
  int maxUniqueSplit(string_view s) {
    size_t ans = 0;
    unsigned sz = s.size();
    unsigned max = 1 << (sz-1);
    unordered_set<string_view> cut;
    for (int m = 0; m < max; m++) {
      if (__builtin_popcount(m) < ans) continue;
      cut.clear();
      bool cont = true;
      for (int i = 0, r = 0; r < sz && cont; r++) {
        if ( (m & (1 << r)) || r == sz-1 ) {
          cont &= cut.insert(s.substr(i, r-i+1)).second;
          i = r+1;
        }
      }
      if (cont) {
        ans = std::max(ans, cut.size());
      }
    }
    return ans;
  }
};
