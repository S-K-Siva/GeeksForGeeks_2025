//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        set<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        q.insert({src,dist[src]});
        
        while(!q.empty()){
            pair<int,int> current = *q.begin();
            q.erase(q.begin());
            int node = current.first;
            int dis = current.second;
            
            for(auto edge : adj[node]){
                int desNode = edge.first;
                int desDis = edge.second;
                
                if(dist[desNode] > dis+desDis){
                    if(dist[desNode] != INT_MAX){
                        q.erase({desNode,dist[desNode]});
                    }
                    dist[desNode] = dis + desDis;
                    q.insert({desNode,dist[desNode]});
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(dist[i] == INT_MAX) dist[i] = 0;
        }
        return dist;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends