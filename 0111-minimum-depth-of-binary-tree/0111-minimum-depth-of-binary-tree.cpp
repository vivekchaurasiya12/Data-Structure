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
    int dfs(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftheight = dfs(root->left);
        int rightheight = dfs(root->right);
        if(leftheight==0){
            return rightheight+1;
        }else if(rightheight==0){
            return leftheight+1;
        }else{
            return min(leftheight,rightheight)+1;
        }
       
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
        
    }
};