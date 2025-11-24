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
    bool isIdentical(TreeNode*p, TreeNode*q){
        if(p==NULL || q==NULL) return p==q;
        bool leftSame = isIdentical(p->left, q->left);
        bool RightSame = isIdentical(p->right, q->right);

        return leftSame && RightSame && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot== NULL || root == NULL) return subRoot == root;
        if(root->val == subRoot->val && isIdentical(root, subRoot)){ 
            return true;
        }

        return  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};