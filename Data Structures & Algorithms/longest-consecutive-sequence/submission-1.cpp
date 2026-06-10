class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1; 
        int curLen = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) continue; 
            if(nums[i] == nums[i-1]+1) {
                curLen +=1;
                maxLen = max(maxLen, curLen);
            } else {
                curLen = 1;
            }
        }
        return maxLen;

    }
};
