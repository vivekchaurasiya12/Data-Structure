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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      
        queue<pair<TreeNode*,TreeNode*>>qt;
        qt.push({p,q});

        while(!qt.empty()){
            int size = qt.size();

            while(size--){
                auto[m,n]=qt.front();
                qt.pop();

                if(m==nullptr && n==nullptr){
                    continue;
                }
                if(m==nullptr || n== nullptr){
                    return false;
                }

                 
                if(m->val != n->val){
                    return false;
                }
               
                qt.push({m->left,n->left});

              
                qt.push({m->right,n->right});
                
                
            }
        }
        return true;
    }
};