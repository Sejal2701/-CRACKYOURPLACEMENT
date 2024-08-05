class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        stack<int> res;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and temperatures[i]>=st.top().first)
            {
                st.pop();
            }
            if(st.empty())
            {
                res.push(0);
                st.push({temperatures[i],i});
            }
            else
            {
                int ind=st.top().second;
                res.push(ind-i);
                st.push({temperatures[i],i});
            }
        }
        
        vector<int> result;
        while(!res.empty())
        {
            result.push_back(res.top());
            res.pop();
        }
        return result;
    }
};