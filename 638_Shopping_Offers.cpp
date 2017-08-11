class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int total = 0; 
        for (int i = 0; i < needs.size(); i++) 
            total += price[i] * needs[i];
        
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
        return total;
    }
};
