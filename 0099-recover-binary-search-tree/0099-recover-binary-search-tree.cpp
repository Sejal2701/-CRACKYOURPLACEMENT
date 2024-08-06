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
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {return;}
        
        inorder(root->left);
        
        if(prev!=NULL and prev->val>root->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first and last)
        {
            int temp=last->val;
            last->val=first->val;
            first->val=temp;
        }
        else if(first and middle)
        {
            int temp=first->val;
            first->val=middle->val;
            middle->val=temp;
        }
        return;
    }
};