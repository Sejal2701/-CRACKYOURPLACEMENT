class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        
        while(num!=0)
        {
            int i=0;
            while(nums[i]>num)
            {
                i++;
            }
            int count=num/nums[i];
            num=num%nums[i];
            for(int k=0;k<count;k++)
            {
                res=res+sym[i];
            }
        }
        return res;
    }
};