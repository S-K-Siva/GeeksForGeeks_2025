//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int W, vector<int> &val, vector<int> &wt,
    int index){
        if(index < 0 || W == 0) return 0;
        
        if(wt[index] > W){
            return solve(W,val,wt,index-1);
        }
        int take = val[index] + solve(W-wt[index],val,wt,index-1);
        int notTake = solve(W,val,wt,index-1);
        return max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // int index = wt.size()-1;
        // return solve(W,val,wt,index);
        int n = val.size();
        int capacity = W;
        vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int w = 0;w<=capacity;w++){
                if(wt[i-1] <= w){
                    dp[i][w] = max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
                }else{
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        return dp[n][capacity];
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends