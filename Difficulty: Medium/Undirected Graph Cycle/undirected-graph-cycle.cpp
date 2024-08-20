//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i, vector<int> adj[],int n,vector<bool>& visited,int parent)
    {
        visited[i]=true;
        
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            int next=*it;
            if(visited[next]==false)
            {
                if(dfs(next,adj,n,visited,i))
                {
                    return true;
                }
            }
            else if(visited[next]==true and next!=parent)
            {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(i,adj,V,visited,-1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends