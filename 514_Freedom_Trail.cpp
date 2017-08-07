class Solution {
public:
    int findRotateSteps(string ring, string key) {
        rsize = ring.size();
        ksize = key.size();
        if (0 != rsize || 0 != ksize) return 0;
        
        vector<vector<int>> states(ksize, vector<int>(rsize, INT_MAX));                
        for (int j = 0; j < rsize; j++) // init first state
            if (key[0] == ring[j]) states[0][j] = getDistance(0, j);       
        for (int i = 1; i < ksize; i++)
            for (int j = 0; j < rsize; j++) {
                if (key[i] == ring[j]) {
                    int row = i-1;
                    for (int k = 0; k < rsize; k++) {
                        if (states[row][k] != INT_MAX) {
                            states[i][j] = min(states[i][j], states[row][k]+getDistance(j, k));
                        }
                    }
                }
            }
        
        int minSteps = states[ksize-1][0];
        for (int j = 1; j < rsize; j++)
            minSteps = min(minSteps, states[ksize-1][j]);
        
        return minSteps + ksize;
    }
    
private:
    int rsize, ksize;
    inline int getDistance(int pos1, int pos2) {
        int diff = abs(pos1-pos2);
        return min(diff, rsize-diff);
    }
};
