class Solution {
public:
    int totalNQueens(int n) {
        ans = 0;
        v.clear();
        v.resize(n);
        h(0, n);
        return ans;
    }
private:
    int ans;
    vector<int> v;
    void h(int row, int n) {
        if (row == n) {
            ++ans;
            return;
        }
        bool ok = true;
        for (int col = 0; col < n; ++col) {
            v[row] = col;
            ok = true;
            for (int i = 0; i < row; i++)
                if (v[i] == col || row-i == abs(v[i]-col)) {
                    ok = false;
                    break;
                }
            if (ok) h(row+1, n);
        }
            
    }
};
