//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '}'){
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }else if(s[i] == ')'){
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            }else if(s[i] == ']'){
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        
        return (st.empty() == true) ? true : false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends