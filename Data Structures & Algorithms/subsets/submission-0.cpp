class Solution {
public:
    set<vector<int>> st; 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        st.clear(); 
        vector<int> vec; 
        func(0, nums, vec, nums.size()); 
        for(auto it: st) {
            ans.push_back(it); 
        }
        return ans;
    }

    void func(int idx, vector<int>& nums, vector<int>& vec, int n) {
        if(idx == n) {
            st.insert(vec);
            return; 
        }

        // take 
        vec.push_back(nums[idx]);
        func(idx+1, nums, vec, n); 

        // not take 
        vec.pop_back(); 
        func(idx+1, nums, vec, n); 
    }
};
