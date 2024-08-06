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
    int paths(TreeNode* root, long long target,long long sum,map<long long,int> mp)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int count=0;
        long long temp=long(root->val);
        sum=sum+temp;
        if(mp[sum-target]>=1)
        {
            count+=mp[sum-target];
        }
        
        if(mp.find(sum)!=mp.end())
        {
            mp[sum]++;
        }
        else
        {
            mp[sum]=1;
        }
        
        count+=paths(root->left,target,sum,mp);
        count+=paths(root->right,target,sum,mp);
        mp[sum]-=1;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int res=0;
        map<long long,int> mp;
        mp[0]=1;
        res=paths(root,targetSum,0,mp);
        return res;
    }
};