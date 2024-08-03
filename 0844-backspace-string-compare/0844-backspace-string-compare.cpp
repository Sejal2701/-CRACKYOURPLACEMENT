class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st;
        stack<int> tt;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#' and !st.empty())
            {
                st.pop();
            }
            else if(s[i]!='#')
            {
                st.push(s[i]);
            }
        }
        
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#' and !tt.empty())
            {
                tt.pop();
            }
            else if(t[i]!='#')
            {
                tt.push(t[i]);
            }
        }
        
        if(st.size()!=tt.size())
        {return false;}
        
        while(!st.empty())
        {
            if(st.top()!=tt.top())
            {return false;}
            st.pop();
            tt.pop();
        }
        return true;
        
    }
};