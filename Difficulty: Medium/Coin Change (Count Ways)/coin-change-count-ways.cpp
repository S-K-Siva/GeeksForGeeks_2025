//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    // void solve(set<vector<int>>& res, int amount,
    // vector<int>& track,vector<int> coins, int idx
    // )
    // {
    //     if(idx >= coins.size() || amount < 0) return;
    //     if(amount == 0){
    //         res.insert(track);
    //         return;
    //     }
    //     track.push_back(coins[idx]);
    //     solve(res,amount-coins[idx],track,coins,idx);
    //     track.pop_back();
    //     solve(res,amount,track,coins,idx+1);
    // }
    // int count(vector<int>& coins, int sum) {
    //     set<vector<int>> res;
    //     vector<int> track;
    //     solve(res,sum,track,coins,0);
    //     return res.size();
    // }
    
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 1;       // Found a valid combination
        if (idx == coins.size()) return 0;  // No more coins to pick
    
        if (dp[idx][amount] != -1) return dp[idx][amount];
    
        int take = 0;
        if (coins[idx] <= amount) {
            take = solve(idx, amount - coins[idx], coins, dp);  // Pick the coin again
        }
        int notTake = solve(idx + 1, amount, coins, dp);        // Skip to next coin
    
        return dp[idx][amount] = take + notTake;
    }
    
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    
        return solve(0, sum, coins, dp);
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends