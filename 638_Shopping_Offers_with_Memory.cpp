class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> dp;
        return helper(price, special, needs, dp);
    }
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, 
               unordered_map<int, int>& dp) {
        int key = needs[0];
        for (int i = 1; i < needs.size(); i++)
            key = key*10 + needs[i]; 
        if (dp.find(key)!= dp.end()) return dp[key];         
        int total = inner_product(price.begin(), price.end(), needs.begin(), 0);
        
        for (int i = 0; i < special.size(); i++) {
            bool useTheSpecial = true;
            for (int j = 0; j < needs.size(); j++) 
                if (special[i][j] > needs[j]) {
                    useTheSpecial = false;
                    break;
                }            
            if (useTheSpecial) {
                int specialPrice = special[i][needs.size()];
                vector<int> remainNeed(needs);
                for (int j = 0; j < needs.size(); j++) 
                    remainNeed[j] -= special[i][j]; 
                total = min(total, specialPrice + shoppingOffers(price, special, remainNeed));
            }
        }
                           
        dp[key] = total;        
        return total;
    }
};
