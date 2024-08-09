class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> s;
        int count=0;
        s[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(s.find(sum-k)!=s.end())
            {
                count+=s[sum-k];
            }
            
            s[sum]++;
        }
        return count;
    }
};