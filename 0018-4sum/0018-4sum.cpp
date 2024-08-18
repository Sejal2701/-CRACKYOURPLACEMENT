class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size(),i=0,j=0,k=0,l=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1])continue;
            
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 and nums[j]==nums[j-1])continue;
                k=j+1;
                l=n-1;
                while(k<l)
                {
                    long long currSum=long(nums[i])+long(nums[j])+long(nums[k])+long(nums[l]);
                    if(currSum==target)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        res.push_back(temp);
                        k++;l--;
                        while(k<l and nums[k]==nums[k-1])
                        {
                            k++;
                        }
                         while(k<l and nums[l]==nums[l+1])
                        {
                            l--;
                        }
                    }
                    else if(currSum>target)
                    {
                        l--;
                         while(k<l and nums[l]==nums[l+1])
                        {
                            l--;
                        }
                    }
                    else
                    {
                        k++;
                        while(k<l and nums[k]==nums[k-1])
                        {
                            k++;
                        }
                    }
                    
                    
                }
                
            }
            
        }
        return res;
    }
};