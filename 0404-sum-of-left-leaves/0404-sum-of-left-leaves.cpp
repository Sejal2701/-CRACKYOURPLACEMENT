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
    void findSumleft(TreeNode*root,int &sum)
    {
        if(root==NULL)
        {return;}
        if(root->left==NULL and root->right==NULL)
        {sum+=root->val;
        return;}
        
        if(root->left!=NULL)
        {findSumleft(root->left,sum);}
        
        if(root->right!=NULL)
        {findSumRight(root->right,sum);}
        
    }
    
    void findSumRight(TreeNode* root,int &sum)
    {
        if(root==NULL)
        {return;}
        if(root->left!=NULL)
        {findSumleft(root->left,sum);}
        
        if(root->right!=NULL)
        {findSumRight(root->right,sum);}
        
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL)
        {return 0;}
        findSumleft(root->left,sum);
        findSumRight(root->right,sum);
        return sum;
    }
};