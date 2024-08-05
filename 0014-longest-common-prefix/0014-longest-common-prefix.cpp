class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
    if(strs.size()==0)
    {
        return res;
    }
        string result = strs[0];
        int len = result.length();

    for (int i = 1; i < strs.size(); i++) 
    {
        while (strs[i].find(result) != 0) {
            result = result.substr(0, len - 1);
            len--;

            if (result.empty()) {
                return res;
            }
        }
    }
    return result;
    }
};