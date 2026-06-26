class Solution {
public:
    int func(int idx,vector<int>& cost, vector<int>& dp, int n) {
        if(idx >= n) return 0; 
        if(idx != -1 && dp[idx] != -1) return dp[idx]; 

        int res = (idx == -1 ) ? min(func(0, cost, dp, n), func(1, cost, dp, n)) : cost[idx] +  min(func(idx+1, cost, dp, n), func(idx+2, cost, dp, n)); 
        if (idx != -1) dp[idx] = res;
        return res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        vector<int> dp(n+1, -1);
        return func(-1, cost, dp, n);
        
    }
};