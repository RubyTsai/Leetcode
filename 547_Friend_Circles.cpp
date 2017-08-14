class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        msize = M.size();
        if (0 == msize) return 0;
        int circles = 0;
        for (int i = 0; i < msize; i++)
            for (int j = i; j < msize; j++) {
                if (M[i][j] == 1) {
                    circles++;
                    M[i][j] = 0;
                    M[j][i] = 0;
                    resetIndirect(j, M);
                }
            }
        return circles;
    }
private:
    int msize;
    void resetIndirect(int cand, vector<vector<int>>& M) {
        for (int j = 0; j < msize; j++) {
            if (M[cand][j] == 1) {
                M[cand][j] = 0;
                M[j][cand] = 0;
                resetIndirect(j, M);
            }
        }        
    }    
};
