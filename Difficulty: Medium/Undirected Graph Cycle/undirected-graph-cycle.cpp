//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool bfs(vector<bool>& vis, vector<vector<int>>& adj, int start){
        
        queue<pair<int,int>> que;
        que.push({-1,start});
        
        while(!que.empty()){
            pair<int,int> current = que.front();
            que.pop();
            int parent = current.first;
            int node = current.second;
            vis[node] = true;
            for(auto neigh : adj[node]){
                if(neigh == parent) continue;
                if(vis[neigh]){
                    return true;
                }
                if(!vis[neigh]) que.push({node, neigh});
            }
        }
        return false;
        
    }
    
    bool dfs(vector<bool>& vis, vector<vector<int>>& adj, int node, int parent){
        vis[node] = true;
        
        for(auto neigh : adj[node]){
            if(neigh == parent) continue;
            if(vis[neigh]) return true;
            if(!vis[neigh]){
                if(dfs(vis,adj,neigh, node) == true) return true;
            }
        }
        
        return false;
    }
    
    int findParent(vector<int>&parent, int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent,parent[node]);
    }
    bool findByRank(vector<int>&parent,vector<int>&rank, int u,int v){
        int ultimateParentOfU = findParent(parent,u);
        int ultimateParentOfV = findParent(parent,v);
        if(ultimateParentOfU == ultimateParentOfV) return true;
        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        }else if(rank[ultimateParentOfU] > rank[ultimateParentOfV]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        }else{
            parent[ultimateParentOfV] = ultimateParentOfU;
            ++rank[ultimateParentOfU];
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        // for(int i = 0;i<n;i++){
        //     if(!visited[i]){
        //         // if(bfs(visited, adj, i) == true) return true;
        //         // if(dfs(visited, adj, i, -1) == true) return true;
                
        //     }
        // }
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        for(int i = 0;i<n;i++){
            for(auto neigh : adj[i]){
                if(i < neigh && findByRank(parent,rank,i,neigh) == true) return true; 
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