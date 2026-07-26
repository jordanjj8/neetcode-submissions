class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1) {
            return 0;
        }
        // l and r
        // 10 1 5 6 7 1
        //            l
        //              r
        // maxprofit = 6
        // 1.  iterate through with r ( day 2) for loop
        // a. if prices[l] >= prices[r]
        // then l = r (move l)
        // b. else if prices[l] < prices[r]
        // update maxprofit 
        int l = 0;
        int maxProfit = 0;

        for (int r= 1; r < prices.size(); r++) {
            if (prices[l] >= prices[r]) {
                l = r;
            } else {
                maxProfit = max(prices[r] - prices[l], maxProfit);
            }
        }

        return maxProfit;

    }
};
