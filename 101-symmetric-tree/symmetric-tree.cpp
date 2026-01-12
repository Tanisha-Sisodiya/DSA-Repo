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
    bool Check(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true ;
        if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))  return false;
        if(root1->val != root2->val) return false;
        return Check(root1->left, root2->right) && Check(root2->left,root1->right);
    }
    bool isSymmetric(TreeNode* root) {
       return Check(root->left, root->right);
    }
};