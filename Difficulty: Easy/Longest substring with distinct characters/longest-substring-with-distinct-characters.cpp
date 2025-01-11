//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int front,rear;
        front = 0;
        rear = 0;
        
        int maxi = 0;
        vector<int> freq(256,0);
        int n = s.size();
        while(front<=rear && rear < n){
            
            if(freq[s[rear] - 'a'] == 1){
                
                freq[s[front] - 'a'] = 0;
                ++front;
            }else{
                freq[s[rear] - 'a'] = 1;
                maxi = max(maxi,rear - front + 1);
                ++rear;
            }
            
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends