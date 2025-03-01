//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum+1,INT_MAX);
        dp[0] = 0;
        for(int i = 0;i<n;i++){
            for(int j = coins[i];j<=sum;j++){
                if(dp[j-coins[i]] != INT_MAX){
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends