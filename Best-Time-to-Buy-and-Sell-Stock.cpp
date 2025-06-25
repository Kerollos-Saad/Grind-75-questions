class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mx=0;        
        int result = 0;

        for(int i=prices.size()-1; i>=0; i--)
        {
            mx = max(mx,prices[i]);
            result = max(result, mx-prices[i]);
        }

        return result;
    }
};