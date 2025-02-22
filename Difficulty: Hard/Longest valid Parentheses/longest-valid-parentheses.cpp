//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> ss;
        int n = s.size();
        int res = 0;
        ss.push(-1);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ss.push(i);
            } else {
                ss.pop(); 
                if (ss.empty()) {
                    ss.push(i); 
                } else {
                    res = max(res, i - ss.top());
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends