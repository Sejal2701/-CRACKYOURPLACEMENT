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
    void path(TreeNode* root,string curr,vector<string>& res)
    {
        string val=to_string(root->val);
        if(curr=="")
        {curr=val;}
        else
        {curr=curr+"->"+val;}
        
        if(root->left==NULL and root->right==NULL)
        {
            res.push_back(curr);
            return;
        }
        
        if(root->left!=NULL)
        {path(root->left,curr,res);}
        if(root->right!=NULL)
        {path(root->right,curr,res);}
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL)
        {
            return res;
        }
        
        path(root,"",res);
        return res;
    }
};