class Solution {
public:
    int func(int idx, vector<int>& cost, vector<int>& dp, int n) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        return dp[idx] = cost[idx] +
                         min(func(idx + 1, cost, dp, n),
                             func(idx + 2, cost, dp, n));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(func(0, cost, dp, n),
                   func(1, cost, dp, n));
    }
};