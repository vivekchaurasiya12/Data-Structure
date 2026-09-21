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

    bool validate(TreeNode* root ,long long min,long long max){
          
          if(root==nullptr){
            return true;
          }

          if(root->val <= min || root->val >= max){
             return false;
          }

         bool left =  validate(root->left,min,root->val);
         bool right =  validate(root->right,root->val,max);
          return left && right;
    }
    bool isValidBST(TreeNode* root) {
          

          return validate(root,LLONG_MIN,LLONG_MAX);
    }
};