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
        if(p==NULL && q!=NULL)
        {
            return false;
        }
        else if(p!=NULL and q==NULL)
        {
            return false;
        }
        if(p==q)
        {
            return true;
        }
        if(p->val==q->val)
        {
            if(isSameTree(p->left,q->left) and isSameTree(p->right,q->right))
            {
                return true;
            }
        }
        return false;
    }
};