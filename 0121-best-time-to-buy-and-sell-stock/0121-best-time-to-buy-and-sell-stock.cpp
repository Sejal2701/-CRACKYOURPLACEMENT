class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMax=0;
        int maxSum=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            if(prices[i]>currMax)
            {
                currMax=prices[i];
            }
            else
            {
                maxSum=max(maxSum,currMax-prices[i]);
            }
        }
        return maxSum;
    }
};