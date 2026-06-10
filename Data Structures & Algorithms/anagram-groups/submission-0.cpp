class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(); 
        vector<int> vis(n, 0); 
        vector<vector<string>> ans; 
        for(int i=0; i<n; i++){
            if(vis[i]) continue; 
            vis[i] = 1; 
            vector<int> hash(26, 0); 
            vector<string> vec; 
            string cur = strs[i];
            vec.push_back(cur); 
            for(auto it: cur) {
                hash[it-'a']++; 
            }
            for(int j=i+1;j<n; j++) {
                string going = strs[j]; 
                vector<int> hash2(26, 0);
                for(auto it: going) {
                    hash2[it-'a']++; 
                } 
                bool flg = true;
                for(int i=0; i<26; i++) {
                    if(hash[i] != hash2[i]) {
                        flg = false; 
                        break;
                    }
                }
                if(flg) {
                    vec.push_back(going);
                    vis[j]= 1;
                }
            }
            ans.push_back(vec);
        }
        return ans; 
    }
};
