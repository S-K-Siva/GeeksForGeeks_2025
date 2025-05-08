//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int val = 0;
        if(arr.size() == 2){
            int val = abs(arr[0] - arr[1]);
            return arr[1] + val;
        }else{
            
            unordered_map<int,int> track;
            for(int i = 1;i<arr.size();i++){
                if(track[abs(arr[i] - arr[i-1])]){
                    val = abs(arr[i] - arr[i-1]);
                    break;
                }else{
                    track[abs(arr[i] - arr[i-1])] = 1;
                }
            }
            for(int i = 1;i<arr.size();i++){
                if(arr[i-1] + val == arr[i]) continue;
                return arr[i-1] + val;
            }
        }
        return arr.back() + val;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends