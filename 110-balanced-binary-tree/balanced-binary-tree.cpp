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
    
    int depth(TreeNode* root){
        if(root==nullptr) return 0;

        int l=depth(root->left);
        int r=depth(root->right);

        return 1+max(l,r);


    }
    bool isBalanced(TreeNode* root) {
      if(root == nullptr) return true;
     int l=depth(root->left);
     int r=depth(root->right);

     if(abs(l-r)>1) return false;

     return isBalanced(root->left) && isBalanced(root->right);


    }
};
