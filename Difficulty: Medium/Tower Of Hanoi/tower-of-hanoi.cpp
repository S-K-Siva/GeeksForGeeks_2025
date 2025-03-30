//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // You need to complete this function

    int towerOfHanoi(int n, int source, int destination,
    int auxilary) {
        if(n == 0) return 0;
        if(n == 1){
            return 1;
        }
        int move1 = towerOfHanoi(n-1,source,auxilary,destination);
        int move2 = towerOfHanoi(n-1,auxilary,destination,source);
        return move1 + move2 + 1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.towerOfHanoi(N, 1, 3, 2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends