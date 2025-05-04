//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        set<char> Set(str.begin(), str.end());
        unordered_map<char,int> mpp;
        int n = str.size();
        int left = 0;
        int result= str.size();
        for(int i = 0;i<n;i++){
            ++mpp[str[i]];
            while(mpp.size() == Set.size() && left <= i){
                result = min(result, i-left+1);
                if(mpp[str[left]] == 1){
                    mpp.erase(str[left]);
                    left++;
                    continue;
                }
                --mpp[str[left++]];
                
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends