class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr=0;
        int z=0;
        while(curr<nums.size() and nums[curr]!=0)
        {
            curr++;
        }
        while(z<nums.size() and curr<nums.size())
        {
            while(z<nums.size() and nums[z]!=0)
            {
                z++;
            }
            
            while(curr<nums.size() and nums[curr]==0)
            {
                curr++;
            }
            if(curr==nums.size() or z==nums.size())
            {
                break;
            }
            swap(nums[curr],nums[z]);
        }
    }
};