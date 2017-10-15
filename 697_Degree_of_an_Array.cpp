class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n: nums) 
            m[n]++;
        
        unordered_map<int, vector<int>> rm;
        int maxf = 0;
        for (auto& kv: m) {
            rm[kv.second].push_back(kv.first);
            maxf = max(maxf, kv.second);
        }
        int ans = nums.size();
        for (int i = 0; i < rm[maxf].size(); i++) {
            int b = 0, e = nums.size()-1;
            for (; nums[b] != rm[maxf][i]; b++);
            for (; nums[e] != rm[maxf][i]; e--);
            ans = min(ans, e-b+1);
        }
        return ans;
    }
};
