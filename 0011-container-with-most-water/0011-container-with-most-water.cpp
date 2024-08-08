class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int start=0;
        int end=height.size()-1;
        
        while(start<end)
        {
            int l=end-start;
            int b=min(height[start],height[end]);
            maxi=max(maxi,l*b);
            if(height[start]<height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return maxi;
    }
};