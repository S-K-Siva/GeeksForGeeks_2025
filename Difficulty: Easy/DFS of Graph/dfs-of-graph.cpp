//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
    void dfs(int node, vector<vector<int>> adj, 
    vector<int>& vis,vector<int>& result){
        vis[node] = 1;
        result.push_back(node);
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis,result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size());
        vector<int> result;
        
        for(int i = 0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis,result);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends