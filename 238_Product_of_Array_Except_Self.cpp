// http://www.cnblogs.com/grandyang/p/4650187.html
// Space: O(2n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> before(size, 1);
        vector<int> after(size, 1);
        for (int i = 1; i < size; i++) 
            before[i] = before[i-1] * nums[i-1];
        for (int i = size-2; i >=0; i--)
            after[i] = after[i+1] * nums[i+1];
        
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
            ans[i] = before[i] * after[i];
        return ans;
    }
};

// Space: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 1);
        for (int i = 1; i < size; i++) 
            ans[i] = ans[i-1] * nums[i-1];
        
        int after = 1;
        for (int i = size-1; i >=0; i--) {
            ans[i] *= after;
            after *= nums[i];
        }
        
        return ans;
    }
};
