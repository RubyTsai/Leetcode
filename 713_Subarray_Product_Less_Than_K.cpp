class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p = 1, ans = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            p *= nums[r];
            
            while (p >= k && l < r) p = p/nums[l++];
            
            if (p < k) ans += 1 + (r-l);
        }
        return ans;
    }
};
//--------------------------------------------------------------------------
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p = nums[0], ans = 0;
        for (int l = 0, r = 0; r < nums.size(); ) {
            if (p < k) {
                ans += 1 + (r-l);
                r++;
                p *= nums[r];
            }
            else p = p/nums[l++];
            
            if (l > r) r = l;
        }
        return ans;
    }
};

//-------------------------------------------------------------------------
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> dp(nums);
        int ans = 0, size = nums.size();
        for (int i = 0; i < size; i++)
            if (nums[i] < k) ans++;
        
        for (int i = 1; i < size; i++)
            for (int j = 0, x = i+j; j < size-i; j++, x++) {
                if (dp[x] > k) continue;
                dp[x] = dp[x] * nums[j];
                if (dp[x] < k) ans++;
            }
        return ans;
    }
};
