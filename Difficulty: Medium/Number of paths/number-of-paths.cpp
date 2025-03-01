//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int numberOfPaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = max(dp[i][j],dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int m, n;
        cin >> m >> n;
        cin.ignore();
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends