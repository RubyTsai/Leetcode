class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        nsize = nums.size();
        return helper(nums, S, 0);
    }
private:
    int nsize;
    int helper(vector<int>& nums, int rest, int index) {
        if (index == nsize) return rest == 0;
        return helper(nums, rest + nums[index], index+1) + 
               helper(nums, rest - nums[index], index+1);
    }
};
