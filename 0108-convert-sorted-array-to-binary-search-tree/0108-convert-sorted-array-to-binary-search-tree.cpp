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
    TreeNode* bst(vector<int>& nums, int start, int end)
    {
        if(start>end)
        {return NULL;}
        
        int mid=(start+end)/2;
        TreeNode* head= new TreeNode(nums[mid]);
        
        TreeNode* left=bst(nums,start,mid-1);
        TreeNode* right=bst(nums,mid+1,end);
        
        head->left=left;
        head->right=right;
        return head;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums,0,nums.size()-1);
    }
};