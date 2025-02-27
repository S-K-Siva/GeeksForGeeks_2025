//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    stack<int> st;
    stack<int> minStack;
  public:
    
    Solution() {
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
        st.push(x);
        
    }

    // Remove the top element from the Stack
    void pop() {
        if(!st.empty())
        {
            if(st.top() == minStack.top()){
                minStack.pop();
            }
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        if(!st.empty())
            return st.top();
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // stack<int> temp;
        // temp = st;
        // int result = INT_MAX;
        // while(!temp.empty()){
        //     result = min(result,temp.top());
        //     temp.pop();
        // }
        // return result == INT_MAX ? -1 : result;
        return minStack.empty() ? -1 : minStack.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends