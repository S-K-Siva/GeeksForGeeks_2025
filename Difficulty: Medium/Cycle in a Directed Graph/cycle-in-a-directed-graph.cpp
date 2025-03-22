//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> inDeg(n);
        
        for(auto it : adj){
            for(auto i : it){
                inDeg[i]++;
            }
        }
        
        queue<int> que;
        for(int i = 0;i<n;i++){
            if(inDeg[i] == 0){
                que.push(i);
            }
        }
        vector<int> res;
        while(!que.empty()){
            int node = que.front();
            res.push_back(node);
            que.pop();
            
            for(auto neigh : adj[node]){
                --inDeg[neigh];
                if(inDeg[neigh] == 0){
                    que.push(neigh);
                }
            }
        }
        return (res.size() == n) ? false : true;
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
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends