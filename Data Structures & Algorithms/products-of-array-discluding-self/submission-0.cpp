class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> leftPart(n, 0), rightPart(n, 0); 
        leftPart[0] = nums[0]; 
        for(int i=1; i<n; i++) leftPart[i] = nums[i] * leftPart[i-1]; 
        rightPart[n-1] = nums[n-1]; 
        for(int i=n-2; i>=0; i--) rightPart[i] = nums[i] * rightPart[i+1]; 
        // for(int i=0; i<n; i++) {
        //     cout<<leftPart[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++) {
        //     cout<<rightPart[i]<<" ";
        // }
        // cout<<endl;
        vector<int> ans(n, 0); 
        for(int i=0; i<n; i++){
            int left = ((i-1) >= 0) ? leftPart[i-1] : 1; 
            int right = ((i+1) < n) ? rightPart[i+1] : 1; 
            // cout<<left<<" "<<right<<endl;
            ans[i] = left*right; 
        }
        return ans; 
    }
};
