class Solution {
public:
    vector<int> vec;

    string encode(vector<string>& strs) {
        vec.clear();           
        string ans = "";
        for (auto &it : strs) {
            vec.push_back(it.size());
            ans += it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int idx = 0;
        string dum = "";

        
        while (idx < vec.size() && vec[idx] == 0) {
            ans.push_back("");
            idx++;
        }

        for (int i = 0; i < s.size(); i++) {
            dum += s[i];

            if (dum.size() == vec[idx]) {
                ans.push_back(dum);
                dum.clear();
                idx++;

               
                while (idx < vec.size() && vec[idx] == 0) {
                    ans.push_back("");
                    idx++;
                }
            }
        }

        return ans;
    }
};
