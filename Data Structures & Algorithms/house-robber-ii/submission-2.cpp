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
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp(n, -1); 
        int firstpass = func(0, dp, nums, n-1); 
        vector<int> dp1(n, -1); 
        int secondpass = func(1, dp1, nums, n); 
        // cout<<firstpass<<" "<<secondpass<<endl;
        return max(firstpass, secondpass);
    }
};
