class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end1=m-1,end2=n-1;
        int curr=m+n-1;
        while(end1>=0 and end2>=0)
        {
            if(nums1[end1]>nums2[end2])
            {
                nums1[curr]=nums1[end1];
                end1--;
            }
            else
            {
                nums1[curr]=nums2[end2];
                end2--;
            }
            curr--;
        }
        while(end2>=0)
        {
            nums1[curr]=nums2[end2];
            end2--;
            curr--;
        }
        
    }
};