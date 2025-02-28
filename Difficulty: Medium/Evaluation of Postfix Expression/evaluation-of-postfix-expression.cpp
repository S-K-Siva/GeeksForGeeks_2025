//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> operands;
        stack<string> operators;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i].size() > 1 || isdigit(arr[i][0])) { // Handles negative numbers
                operands.push(stoi(arr[i]));
            } else {
                operators.push(arr[i]);
            }
            
            while (operands.size() >= 2 && !operators.empty()) {
                int first = operands.top();
                operands.pop();
                int second = operands.top();
                operands.pop();
                
                int new_one = 0;
                string op = operators.top();
                operators.pop();

                if (op == "+") new_one = second + first;
                else if (op == "-") new_one = second - first;
                else if (op == "*") new_one = second * first;
                else if (op == "/") new_one = second / first;

                operands.push(new_one);
            }
        }
        return operands.top();
    
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends