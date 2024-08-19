class Solution {
public:
    void find(vector<int>& candidates,int target,vector<int> curr,vector<vector<int>>& res,int i)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        else if(target<0 or i>=candidates.size())
        {return;}
        
            if(candidates[i]!=0)
            {
                if(i==0)
                {
                    find(candidates,target,curr,res,i+1);
                    
                    int temp=candidates[i];
                    candidates[i]=0;
                    curr.push_back(temp);
                    find(candidates,target-temp,curr,res,i+1);
                    curr.pop_back();
                    candidates[i]=temp;
                }
                else if(candidates[i-1]!=candidates[i])
                {
                    find(candidates,target,curr,res,i+1);
                    
                    int temp=candidates[i];
                    candidates[i]=0;
                    curr.push_back(temp);
                    find(candidates,target-temp,curr,res,i+1);
                    curr.pop_back();
                    candidates[i]=temp;
                }
                else
                {
                    find(candidates,target,curr,res,i+1);
                }
            }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        
        find(candidates,target,curr,res,0);
        
        return res;
    }
};