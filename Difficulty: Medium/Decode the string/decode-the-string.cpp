//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0;i<n;i++){
            if(s[i] == ']'){
                string current = "";
                while(!st.empty() && st.top() != '['){
                    current = st.top() + current;
                    st.pop();
                }
                st.pop();
                string resultString = "";
                   
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int value = numStr.empty() ? 1 : stoi(numStr);

                    while(value--){
                        resultString += current;
                    }
                
                for(int i = 0;i<resultString.size();i++){
                    st.push(resultString[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends