class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, low = 0;
        for (int i = 0; i < prices.size(); i++) {
        	if (prices[i] - prices[low] > profit) {
        		profit = prices[i] - prices[low];
        	}
        	if (prices[i] < prices[low]) {
        		low = i;
        	}
        }
        return profit;
    }
};
