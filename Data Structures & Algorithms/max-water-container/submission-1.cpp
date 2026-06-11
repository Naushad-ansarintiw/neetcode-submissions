// class Solution {
// public:
//     int maxArea(vector<int>& heights) {
//         int maxAreaWater = 0; 
//         int n = heights.size(); 
//         for(int i=0; i<n-1; i++) {
//             for(int j=i+1; j<n; j++) {
//                 int area = (j-i) * min(heights[i], heights[j]);
//                 maxAreaWater = max(maxAreaWater, area);
//             }
//         }
//         return maxAreaWater;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};