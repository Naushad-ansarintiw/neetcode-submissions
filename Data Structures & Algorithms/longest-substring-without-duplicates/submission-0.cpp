class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        int l=0,r=0; 
        unordered_map<char,int> mp;

        int ans = 0; 
        while(r<n) {
            if(mp.find(s[r]) == mp.end()) {
                // not found first time
                mp[s[r]] = 1; 
                ans = max(ans, r-l+1);
                r++;
            }
            else {
                mp.erase(s[l]);
                l+=1;
            }

        }
        return ans;
    }
};
