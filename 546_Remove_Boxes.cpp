class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        unordered_map<int, int> dp;
        return helper(boxes, dp);
    }    
private:
    int helper(vector<int>& boxes, unordered_map<int, int>& dp) {
        int bsize = boxes.size();
        if (bsize == 0 || bsize == 1) return bsize;
        int key = boxes[0];
        for (int i = 1; i < bsize; i++) key = key * 10 + boxes[i];
        if (dp.find(key) != dp.end()) return dp[key];
        
        int points = 0;
        int same = 1;
        for (int i = 0; i < bsize; i += same) {
            same = 1;
            while (i + same < bsize && boxes[i+same] == boxes[i])
                same++;
            vector<int> newSeg;
            for (int j = 0; j < i; j++) newSeg.push_back(boxes[j]);
            for (int j = i+same; j < bsize; j++) newSeg.push_back(boxes[j]);
            points = max(points, same*same + helper(newSeg, dp));
        }
        dp[key] = points;
        return points;
    }
};
