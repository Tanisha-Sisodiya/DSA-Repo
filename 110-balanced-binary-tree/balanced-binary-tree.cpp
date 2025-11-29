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
    int height(TreeNode* root, vector<int>& diff){
        if(root == NULL) return 0;
        int leftheight = height(root->left, diff);
        int rightheight = height(root->right, diff);
        diff.push_back(leftheight - rightheight);
        return max(leftheight, rightheight)+1;
    }
    bool isBalanced(TreeNode* root) {
        vector<int> diff;
        height(root, diff);
        int n = diff.size();
        for(int i = 0; i<n; i++){
            if(diff[i]>1 || diff[i]<-1 ) return false;
        }
        return true;
    }
};