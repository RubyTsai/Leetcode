class Solution {
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int rowSz = heights.size();
    int colSz = heights[0].size();
    int numElmt = rowSz * colSz;

    using PII = pair<int, int>;
    int dir[] = { 0, -1, 0, 1, 0 };
    vector<int> effort(numElmt, INT_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    effort[0] = 0;
    pq.emplace(0, 0);
    while ( !pq.empty() ) {
      auto [d, curr] = pq.top();
      if (curr == numElmt-1) return d; 
      if (d > effort[curr]) continue;

      int r = curr / rowSz;
      int c = curr % rowSz;
      pq.pop();

      int currDiff = effort[curr];
      for (int i = 0; i < 4; i++) {
        int ni = r + dir[i];
        int nj = c + dir[i+1];
        int nIndx = ni * rowSz + nj;
        if ( ni < 0 || nj < 0 ||
             ni == rowSz || nj == colSz) continue;
        if ( currDiff >= effort[nIndx]) continue;
        int diff = abs(heights[r][c] - heights[ni][nj]);
        int maxDiff = max(currDiff, diff);
        effort[nIndx] = maxDiff;
        pq.emplace(maxDiff, ni*rowSz + nj);
      }
    }
    return -1;
  }
};
