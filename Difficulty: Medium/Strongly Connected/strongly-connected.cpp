//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
  
    void dfs(int node, vector<vector<int>>&adj, vector<int> &vis,
    stack<int>& st){
        vis[node] = 1;
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis, st);
            }
        }
        st.push(node);
    }
    void dfsTranspose(int node, vector<vector<int>>& adj, vector<int>&vis){
        vis[node] = 1;
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfsTranspose(neigh, adj, vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj, vis,st);
            }
        }
        vector<vector<int>> adjT(n,vector<int>());
        for(int i = 0;i<n;i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        int count = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ++count;
                dfsTranspose(node,adjT,vis);
            }
            
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends