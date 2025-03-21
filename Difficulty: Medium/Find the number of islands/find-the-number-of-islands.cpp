//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int x,int y,vector<vector<char>>& grid,
    vector<vector<int>>& vis){
        vis[x][y] = 1;
        
        vector<int> dx = {0,0,1,-1,1,1,-1,-1};
        vector<int> dy = {1,-1,0,0,1,-1,1,-1};
        
        for(int i = 0;i<8;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < grid.size() &&
            newY >= 0 && newY < grid[0].size() &&
            !vis[newX][newY] && grid[newX][newY] == '1'){
                dfs(newX,newY, grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    ++cnt;
                }
            }
        }
        return cnt;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends