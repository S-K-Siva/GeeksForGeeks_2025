//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        if(image[sr][sc] == newColor) return image;
        queue<pair<int,int>> que;
        que.push({sr,sc});
        int oldColour = image[sr][sc];
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        while(!que.empty()){
            pair<int,int> cur = que.front();
            que.pop();
            int x = cur.first;
            int y = cur.second;
            image[x][y] = newColor;
            for(int i = 0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < image.size() &&
                newY >= 0 && newY < image[0].size() &&
                image[newX][newY] == oldColour){
                    que.push({newX,newY});
                }
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends