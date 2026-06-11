class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAreaWater = 0; 
        int n = heights.size(); 
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int area = (j-i) * min(heights[i], heights[j]);
                maxAreaWater = max(maxAreaWater, area);
            }
        }
        return maxAreaWater;
    }
};
