class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string res="";
        while(columnNumber!=0)
        {
            int temp=columnNumber%26;
            if(temp==0)
            {res='Z'+res;
            columnNumber=(columnNumber/26)-1;}
            else
            {
                char t=(temp-1+'A');
                res=t+res;
                columnNumber/=26;
            }
            
        }
        return res;
    }
};