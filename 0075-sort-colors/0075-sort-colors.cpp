class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        
        while(mid<=end)
        {
            if(nums[mid]==0)
            {
                nums[mid]=nums[start];
                nums[start]=0;
                start++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                nums[mid]=nums[end];
                nums[end]=2;
                end--;
            }
            else
            {
                mid++;
            }
        }
        
    }
};