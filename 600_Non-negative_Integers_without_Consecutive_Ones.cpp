class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(2, 0);
        vector<int> bits(1, 0);
        int msb = 0, result = num+1;
        for (; num > 0; msb++, num >>= 1) {
            if (num&1 == 1) bits.push_back(1);
            else bits.push_back(0);
        }
        for (int j = 2, pow = 1; j <=msb; j++, pow <<= 1)
            dp.push_back(dp[j-1] + pow + dp[j-2]);
        
        result -= helper(msb, dp, bits);
        return result;
    }
    int helper (int msb, vector<int>& dp, vector<int>& bits) {
        if (msb <= 1) return 0;
        int result = dp[msb-1];
        if (bits[msb-1] == 1) {
            for (int i = 1, pow = 1; i < msb-1; i++, pow <<= 1) 
                result += bits[i]==1? pow: 0;
            result++; // the number itself
            result += msb-2 > 0 ? dp[msb-2]: 0;
        }
        else {
            int nextMsb = msb-2;
            while (bits[nextMsb] == 0) nextMsb--;
            result += helper(nextMsb, dp, bits);
        }
        return result;
    }
};
