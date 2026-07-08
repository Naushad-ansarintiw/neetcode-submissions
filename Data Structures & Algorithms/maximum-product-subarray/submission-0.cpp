class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -11; 
        int n = nums.size(); 
        for(int i=0; i<n; i++) {
            int prod = 1; 
            for(int j=i; j<n; j++) {
                prod = prod * nums[j]; 
                ans = max(ans, prod);
            }
        }
        return ans; 

    }
};
