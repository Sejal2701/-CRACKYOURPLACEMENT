class Solution {
public:
    void find(vector<vector<int>>& res,int i,int k,vector<int> curr,int n)
    {
        if(k==0)
        {
            res.push_back(curr);
            return;
        }
        
        if(i>n)
        {return;}

        curr.push_back(i);
        find(res,i+1,k-1,curr,n);
        curr.pop_back();
        
        find(res,i+1,k,curr,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        for(int i=1;i<=n;i++)
        {
            curr.push_back(i);
            find(res,i+1,k-1,curr,n);
            curr.pop_back();
        }
        return res;
    }
};