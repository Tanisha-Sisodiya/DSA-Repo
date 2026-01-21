/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* preOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = preOrder(root->left,p,q);
        TreeNode* right = preOrder(root->right,p,q);
        if(left != NULL && right != NULL){
            return root;
        } 
        if(left != NULL){
            return left;
        }
        
        return right;
        
   }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return preOrder(root, p, q);


       
    }
};
