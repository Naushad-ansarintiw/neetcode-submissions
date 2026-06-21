class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> partition(string s) {
        vector<string> vec;
        palindromePartition(0, "", vec, s);
        return ans;
    }

    void palindromePartition(int idx, string curString,
                             vector<string>& vec, string& s) {

        // base case
        if (idx == s.size()) {
            if (curString.empty()) {
                ans.push_back(vec);
            } else if (isPalindrome(curString)) {
                vec.push_back(curString);
                ans.push_back(vec);
                vec.pop_back();
            }
            return;
        }

        string newS = curString + s[idx];

        // Cut here if palindrome
        if (isPalindrome(newS)) {
            vec.push_back(newS);
            palindromePartition(idx + 1, "", vec, s);
            vec.pop_back();
        }

        // Don't cut here
        // Avoid duplicate generation at the last character
        if (idx != s.size() - 1) {
            palindromePartition(idx + 1, newS, vec, s);
        }
    }

    bool isPalindrome(const string& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};