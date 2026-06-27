class Solution {
public:
    int func(int idx, vector<int>& dp, vector<int>& nums, int n) {
        if(idx >= n) return 0; 
        if(dp[idx] != -1) return dp[idx];
        int rob = nums[idx] + func(idx+2, dp, nums, n); 
        int notRob = 0 + func(idx+1, dp, nums, n); 
        return dp[idx] = max(rob, notRob); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp(n, -1); 
        return func(0, dp, nums, n);
    }
};
