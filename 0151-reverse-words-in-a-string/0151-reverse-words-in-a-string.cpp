class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;
        while(i<s.size())
        {
            string temp="";
            while(i<s.size() and s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            if(temp.size()>0)
            {st.push(temp);}
            while(i<s.size() and s[i]==' ')
            {
                i++;
            }
        }
        string res="";
        while(!st.empty())
        {
            res=res+st.top();
            if(st.size()>1)
            {
                res+=" ";
            }
            st.pop();
        }
        return res;
    }
};