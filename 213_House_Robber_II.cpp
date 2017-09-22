class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty()? 0: nums[0]; 
        int choice1 = rob(nums, 0, nums.size() - 1);
        int choice2 = rob(nums, 1, nums.size());;    
        return max(choice1, choice2);
    }    
private:
    int rob(vector<int>& nums, int begin, int end) {
        int diff = end - begin;
        switch (diff) {
            case 1: return nums[begin];
            case 2: return max(nums[begin], nums[begin+1]);
        } 
        int a = nums[begin], b = max(nums[begin], nums[begin+1]);
        
        for (int i = begin+2; i < end; i++) {
            a = max(b, a + nums[i]);
            swap(a, b);
        }
        return b;
    }
};

/* -------------------------------------------------------

因為首尾相連，所以第一家和最後一家只能搶其中的一家，或者都不搶。
解法：把第一家和最後一家分别去掉，各算一遍，取其最大的值

---------------------------------------------------------*/
