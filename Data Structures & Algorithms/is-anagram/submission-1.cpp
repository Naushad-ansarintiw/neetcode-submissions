class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26, 0);
        for(auto it: s) {
            arr[it-'a']++;
        }
        for(auto it: t) {
            arr[it-'a']--;
        }
        // for(int i=0; i<26; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        for(int i=0; i<26; i++){
            if(arr[i] > 0 || arr[i] < 0) return false;
        }
        return true; 
    }
};
