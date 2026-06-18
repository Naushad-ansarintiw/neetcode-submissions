/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int,bool> ischeck(TreeNode* node) {
        if(node == NULL) return {0, true};
        pair<int,bool> lf = ischeck(node->left); 
        pair<int,bool> rg = ischeck(node->right);  
        int dif = abs(lf.first - rg.first); 
        if(lf.second == false || rg.second == false || dif > 1 ) return {INT_MIN, false};
        return {1+max(lf.first, rg.first), true};

    }
    bool isBalanced(TreeNode* root) {
        return ischeck(root).second;
    }
};
