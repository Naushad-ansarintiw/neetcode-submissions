class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        if(n==1) return 0; 
        int maxprofit = 0; 
        vector<int> rightMax(n, 0); 
        rightMax[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--) rightMax[i] = max(rightMax[i+1], prices[i]);
        for(int i=0; i<n-1; i++) maxprofit = max(maxprofit, rightMax[i]-prices[i]);
        return maxprofit;
    }
};
