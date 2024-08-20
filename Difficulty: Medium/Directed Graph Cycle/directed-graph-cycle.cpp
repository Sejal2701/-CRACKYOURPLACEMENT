//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> pq;
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                pq.push(i);
            }
        }
        while(!pq.empty())
        {
            int temp=pq.front();
            for(auto it:adj[temp])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    pq.push(it);
                }
            }
            count++;
            pq.pop();
        }
        
        if(count==V)
        {
            return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends