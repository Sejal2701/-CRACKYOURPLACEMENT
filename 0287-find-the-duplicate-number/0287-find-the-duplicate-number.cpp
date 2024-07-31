class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=-1;
        
        while(fast!=slow)
        {
            if(fast==-1)
            {fast=0;}
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        fast=0;
        while(fast!=slow)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return fast;
    }
};