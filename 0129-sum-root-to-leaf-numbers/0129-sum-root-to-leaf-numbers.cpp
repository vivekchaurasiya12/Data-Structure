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
    int ans=0;
    void dfs(TreeNode* root,int current){
        if(root==nullptr){
            return;
        }
        current = current * 10 + root->val;
        if(root->left==nullptr && root->right==nullptr){
            ans += current;
        }

        dfs(root->left,current);
        dfs(root->right,current);

      

    }
    
    int sumNumbers(TreeNode* root) {
        
        dfs(root,0);
        return ans;
        
    }
};