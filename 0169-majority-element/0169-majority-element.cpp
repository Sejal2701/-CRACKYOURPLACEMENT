class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int el=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                count=1;
                el=nums[i];
            }
            else if(nums[i]==el)
            {
                count++;
            }
            else if(nums[i]!=el)
            {
                count--;
            }
        }
        return el;
    }
};