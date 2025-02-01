//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    
    bool dfs(string& target, vector<vector<char>>& board,
             vector<vector<int>>& vis, int row, int col, int n, int m, int idx) 
    {
        if (idx == target.size()) return true;
        
        vis[row][col] = 1;
        
        for (int k = 0; k < 4; k++) {
            int newX = row + x[k];
            int newY = col + y[k];

            if (newX >= 0 && newY >= 0 && newX < n && newY < m &&
                board[newX][newY] == target[idx] && !vis[newX][newY]) {
                
                if (dfs(target, board, vis, newX, newY, n, m, idx + 1)) {
                    return true;
                }
            }
        }
        
        vis[row][col] = 0; 
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string& word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (dfs(word, board, vis, i, j, n, m, 1)) return true;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends