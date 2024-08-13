class Solution {
public:
    void paren(int left,int right,string s,vector<string>& ans)
    {
        if(left==0 and right==0)
        {
            ans.push_back(s);
        }
        
        if(right<left or left<0 or right<0)
        {
            return;
        }
        
        paren(left-1,right,s+"(",ans);
        
        paren(left,right-1,s+")",ans);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        paren(n,n,"",res);
        return res;
    }
};