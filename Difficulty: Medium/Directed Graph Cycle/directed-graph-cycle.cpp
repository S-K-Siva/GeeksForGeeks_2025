//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V,vector<int>());
        
        
        vector<int> indeg(V);
        for(auto edge : edges){
            indeg[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        queue<int> que;
        for(int i = 0;i<V;i++){
            if(indeg[i] == 0){
                que.push(i);
            }
        }
        vector<int> result;
        while(!que.empty()){
            result.push_back(que.front());
            int node = que.front();
            que.pop();
            
            for(auto neigh : adj[node]){
                --indeg[neigh];
                if(indeg[neigh] == 0){
                    que.push(neigh);
                }
            }
        }
        return (result.size() == V) ? false : true;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends