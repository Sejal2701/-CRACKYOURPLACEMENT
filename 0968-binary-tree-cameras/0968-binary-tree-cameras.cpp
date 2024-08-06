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
    //0 ->covered
    //1 ->has camera
    //2 ->not covered
    int cam=0;
    int minCameraCover(TreeNode* root) {
        if(covered(root)==2)
        {cam++;}
        return cam;
    }
    int covered(TreeNode* root)
    {
        if(root==NULL)
        {return 0;}
        int l=covered(root->left);
        int r=covered(root->right);
        
        if(l==2 or r==2)
        {
            cam++;
            return 1;
        }
        else if(l==0 and r==0)
        {
            return 2;
        }
        return 0;
    }
};