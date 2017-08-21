class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {              
        set<vector<int>> ans;      
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> seqs(ans.begin(), ans.end());
            for (auto& seq: seqs) {
                if (seq.back() <= nums[i]) {
                    seq.push_back(nums[i]);
                    ans.insert(seq);
                }
            }
            ans.insert(vector<int>(1, nums[i]));
        }
        
        vector<vector<int>> res;
        for (auto& seq: ans) {
            if (seq.size() > 1) res.push_back(seq);
        }
        return res;
    }
};
