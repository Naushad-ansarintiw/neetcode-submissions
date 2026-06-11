class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        vector<int> rightMax(n, 0); 
        rightMax[n-1] = height[n-1]; 
        for(int i=n-2 ;i>=0; i--) rightMax[i] = max(rightMax[i+1], height[i]);
        int leftmax = height[0];
        int ans =0;
        for(int i=0; i<n; i++) {
            leftmax = max(leftmax, height[i]);
            // cout<<leftmax <<","<<(min(leftmax, rightMax[i]) - height[i])<<" ";
            ans += (min(leftmax, rightMax[i]) - height[i]);
        }
        cout<<endl;
        return ans;
    }
};
