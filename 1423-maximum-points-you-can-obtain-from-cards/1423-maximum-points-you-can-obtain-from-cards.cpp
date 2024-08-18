class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int right=0;
        int left=0;
        int res=0;
        int n=cardPoints.size();
        
        for(int i=0;i<k;i++)
        {
            left+=cardPoints[i];
        }
        res=left;
        
        for(int i=0;i<k;i++)
        {
            left-=cardPoints[k-i-1];
            right+=cardPoints[n-i-1];
            res=max(res,left+right);
        }
        return res;
    }
};