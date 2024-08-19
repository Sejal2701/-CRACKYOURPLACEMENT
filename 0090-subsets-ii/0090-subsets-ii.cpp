class Solution {
public:
    void find(vector<vector<int>>& res,vector<int> curr,vector<int> nums,int i)
    {
        if(i==nums.size())
        {
            res.push_back(curr);
            return;
        }
        
        if(i==0)
        {
            find(res,curr,nums,i+1);
            
            int temp=nums[i];
            nums[i]=11;
            curr.push_back(temp);
            find(res,curr,nums,i+1);
            curr.pop_back();
            nums[i]=temp;
        }
        else if(nums[i]!=nums[i-1])
        {
            find(res,curr,nums,i+1);
            
            int temp=nums[i];
            nums[i]=11;
            curr.push_back(temp);
            find(res,curr,nums,i+1);
            curr.pop_back();
            nums[i]=temp;   
        }
        else
        {
            find(res,curr,nums,i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
      
        find(res,curr,nums,0);   
        
        
        return res;
    }
};