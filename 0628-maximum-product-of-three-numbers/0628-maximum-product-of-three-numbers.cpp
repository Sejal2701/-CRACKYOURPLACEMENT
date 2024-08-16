class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int smaxi=INT_MIN;
        int tmaxi=INT_MIN;
        
        int mini=INT_MAX;
        int smini=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=maxi)
            {
                tmaxi=smaxi;
                smaxi=maxi;
                maxi=nums[i];
            }
            else if(nums[i]<=maxi and nums[i]>smaxi)
            {
                tmaxi=smaxi;
                smaxi=nums[i];
            }
            else if(nums[i]<=smaxi and nums[i]>tmaxi)
            {
                tmaxi=nums[i];
            }
            if(nums[i]<=mini)
            {
                smini=mini;
                mini=nums[i];
            }
            else if(nums[i]>=mini and nums[i]<smini)
            {
                smini=nums[i];
            }
        }
        return max(smini*mini*maxi, maxi*smaxi*tmaxi);
    }
};