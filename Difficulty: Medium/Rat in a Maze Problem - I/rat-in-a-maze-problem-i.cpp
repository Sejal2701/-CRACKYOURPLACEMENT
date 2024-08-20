//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void paths(vector<vector<int>> mat,int i,int j,string curr,vector<string>& res)
    {
        int m=mat.size();
        int n=mat[0].size();
        if(i==m-1 and j==n-1)
        {
            res.push_back(curr);
            return;
        }
        
        mat[i][j]=-1;
        
        if(i+1<mat.size() and mat[i+1][j]==1)
        {
            curr.push_back('D');
            paths(mat,i+1,j,curr,res);
            curr.pop_back();
        }
        if(j+1<mat[0].size() and mat[i][j+1]==1)
        {
            curr.push_back('R');
            paths(mat,i,j+1,curr,res);
            curr.pop_back();
        }
        if(i-1>=0 and mat[i-1][j]==1 )
        {
            curr.push_back('U');
            paths(mat,i-1,j,curr,res);
            curr.pop_back();
        }
        if(j-1>=0 and mat[i][j-1]==1 )
        {
            curr.push_back('L');
            paths(mat,i,j-1,curr,res);
            curr.pop_back();
        }
        mat[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> res;
        if(mat[0][0]==0)
        {
            return res;
        }
        
        
        paths(mat,0,0,"",res);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends