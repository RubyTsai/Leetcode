class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        priority_queue<int> pq;
        int n = nums[0];
        int maxi = 0, maxn = n;
        pq.push(n);
        for (int i = 1; i < nums.size(); i++) {
            n = nums[i];
            pq.push(n);
            if (maxn < n) maxn = n, maxi = i;
        }
        pq.pop();
        
        while (!pq.empty() && pq.top() == maxn) 
            pq.pop();
        
        if (!pq.empty() && pq.top()*2 > maxn) return -1;
        else return maxi;
    }
};
