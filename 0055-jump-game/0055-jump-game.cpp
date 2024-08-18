#include <algorithm>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> possible(nums.size(),false);
        int n=nums.size();
        possible[n-1]=true;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                continue;
            }
            int temp=min(i+nums[i],n-1);

            while(temp>i)
            {
                if(possible[temp]==true)
                {
                    possible[i]=true;
                    break;
                }
                temp--;
            }
            
        }
        return possible[0];
    }
};