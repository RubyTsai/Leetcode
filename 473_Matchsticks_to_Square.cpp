class Solution {
public:
    bool makesquare(vector<int>& nums) {
        nsize = nums.size();
        int sum = 0;
        for (int n: nums) sum += n;
        if (sum % 4 != 0 || nsize < 4) return false;
        
        edge = sum >> 2;
        int boxes[4] = { 0 };
        sort(nums.rbegin(), nums.rend());
        return helper(0, nums, boxes);
    }    
private:
    int nsize, edge;
    bool helper(int index, vector<int>& nums, int boxes[4]) {
        if (index == nsize) {
            if (boxes[0] == edge && boxes[1] == edge && boxes[2] == edge)                 
                return true;
            return false;
        }
        
        for (int i = 0; i < 4; i++) {
            if (nums[index] + boxes[i] > edge) continue;
            boxes[i] += nums[index];
            if (helper(index+1, nums, boxes)) return true;
            boxes[i] -= nums[index];
        }
        return false;
    }
};
