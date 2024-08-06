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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxi=0;
        
        while(!q.empty())
        {
            long long start=0;
            long long end;
            long long sub=q.front().second;
            int k=q.size();
            while(k--)
            {
                TreeNode* temp=q.front().first;
                long long ind=q.front().second-sub;
                end=ind;
                q.pop();
                
                if(temp->left)
                {
                    q.push({temp->left,ind*2+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,ind*2+2});
                }
            }
            maxi=max(maxi,end-start+1);
        }
        int res=int(maxi);
        return res;
    }
};