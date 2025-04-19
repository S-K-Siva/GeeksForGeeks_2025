//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // int maxXor(vector<int> &arr) {
    //     int res = 0;
    //     int n = arr.size();
    //     for(int i = 0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //             res = max(res, arr[i]^arr[j]);
    //         }
    //     }
    //     return res;
    // }
    int maxXor(vector<int>& nums) {
    int maxResult = 0, mask = 0;
    
    for (int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        
        for (int num : nums) {
            prefixes.insert(num & mask); // keep only left i bits
        }

        int candidate = maxResult | (1 << i);
        
        for (int prefix : prefixes) {
            if (prefixes.count(prefix ^ candidate)) {
                maxResult = candidate;
                break;
            }
        }
    }
    
    return maxResult;
}

};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends