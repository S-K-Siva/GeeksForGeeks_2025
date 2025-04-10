//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int start,vector<vector<int>> adj, 
    vector<int>& vis){
        queue<pair<int,int>> que;
        que.push({-1,start});
        
        while(!que.empty()){
            int parent = que.front().first;
            int node = que.front().second;
            vis[node] = 1;
            que.pop();
            for(auto neigh : adj[node]){
                if(neigh == parent) continue;
                if(vis[neigh]) return true;
                if(!vis[neigh]) que.push({node,neigh});
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
      
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis) == true) return true;
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
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends