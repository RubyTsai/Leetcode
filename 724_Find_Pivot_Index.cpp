class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size, 0), right(size, 0);
        
        for (int i = 1; i < size; i++) 
            left[i] = left[i-1] + nums[i-1];
        
        for (int i = size-2; i >= 0; i--)
            right[i] = right[i+1] + nums[i+1];
        
        for (int i = 0; i < size; i++)
            if (left[i] == right[i]) return i;
        return -1;
    }
};
