//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void permutation(vector<int> arr,vector<vector<int>>& ans,vector<int> per,vector<bool> vis,int n,int count)
    {
        if(count==n)
        {
            ans.push_back(per);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                if(i>0)
                {
                    if(arr[i]!=arr[i-1] or vis[i-1]==true)
                    {
                        vis[i]=true;
                        per.push_back(arr[i]);
                        permutation(arr,ans,per,vis,n,count+1);
                        vis[i]=false;
                        per.pop_back();
                    }
                }
                else
                {
                    vis[i]=true;
                    per.push_back(arr[i]);
                    permutation(arr,ans,per,vis,n,count+1);
                    vis[i]=false;
                    per.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> per;
        vector<bool> vis(n,false);
        
        permutation(arr,ans,per,vis,n,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends