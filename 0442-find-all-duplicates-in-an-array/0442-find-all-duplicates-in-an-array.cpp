class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
            int idx=abs(nums[i]);
            if(nums[idx-1]<0)
            {
                res.push_back(abs(nums[i]));
            }
            else
            {
                nums[idx-1]*=-1;
            }
        }
        
        return res;
    }
};