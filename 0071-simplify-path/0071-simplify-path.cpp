class Solution {
public:
    string simplifyPath(string path) {
        string dir="";
        string res="/";
        int i=0;
        stack<string> st;
        while(i<path.size())
        {
            dir.clear();
            
            while(path[i]=='/')
            {
                i++;
            }
            
            while(i<path.size() and path[i]!='/')
            {
                dir=dir+path[i];
                i++;
            }
            
            
            if(dir.compare("..")==0)
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(dir.compare(".")==0)
            {
                continue;
            }
            else if(dir.size()!=0)
            {
                st.push(dir);
            }
        }
        
        stack<string> st1;
        while(!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty())
        {
            string temp = st1.top();

            if (st1.size() >1)
            {res.append(temp + "/");}
            else
            {res.append(temp);}
 
            st1.pop();
        }
        return res;
    }
};