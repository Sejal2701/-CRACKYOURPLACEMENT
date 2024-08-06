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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
        {return res;}

        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;

        while(!q.empty())
        {
            int len=q.size();
            vector<int> tempRow(len);
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                if(flag)
                {tempRow[i]=temp->val;}
                else
                {tempRow[len-i-1]=temp->val;}

                if(temp->left!=NULL)
                {q.push(temp->left);}
                if(temp->right!=NULL)
                {q.push(temp->right);}
            }
            flag=!flag;
            res.push_back(tempRow);
        }
        return res;
    }
};


















