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
    bool traverse(TreeNode* root, TreeNode* node, vector<TreeNode*>& vec) {
        if(root == NULL) return false; 
        vec.push_back(root); 
        if(root->val == node->val) return true; 
        bool lf = traverse(root->left, node, vec); 
        if(lf) return true;
        bool rg = traverse(root->right, node, vec); 
        if(rg) return true; 
        vec.pop_back(); 
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> pPath, qPath; 
        // traverse(root, p, pPath); 
        // traverse(root, q, qPath);
        // int t=0; 
        // while(t<pPath.size() && t<qPath.size()) {
        //     if(pPath[t]->val == qPath[t]->val) t++;
        //     else break;
        // }
        // return pPath[t-1];

        // second methond
        if(root == NULL || root == p || root == q) return root; 
        TreeNode* left = lowestCommonAncestor(root->left, p, q); 
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 
        if(left == NULL) return right; 
        else if(right == NULL) return left; 
        else return root; 
    }
};
