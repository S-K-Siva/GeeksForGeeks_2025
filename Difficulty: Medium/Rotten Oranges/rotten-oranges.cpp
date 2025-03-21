//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        queue<pair<int,int>> que;
        int n = mat.size();
        int m = mat[0].size();
        int fresh = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 2) que.push({i,j});
                if(mat[i][j] == 1) ++fresh;
            }
        }
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        int cnt = 0;
        while(!que.empty()){
            queue<pair<int,int>> temp;
            int found = 0;
            while(!que.empty()){
                pair<int,int> current;
                current = que.front();
                que.pop();
                
                int x = current.first;
                int y = current.second;
                
                for(int i = 0;i<4;i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    
                    if(newX >= 0 && newX < n &&
                    newY >= 0 && newY < m &&
                    mat[newX][newY] == 1){
                        mat[newX][newY] = 2;
                        temp.push({newX,newY});
                        --fresh;
                        found = 1;
                    }
                }
            }
            if(found)
                cnt++;
            que = temp;
        }
        return (fresh > 0) ? -1 : cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends