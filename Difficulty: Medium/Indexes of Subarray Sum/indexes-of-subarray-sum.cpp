//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        
        int start = 0;
        int end = 0;
        int n = arr.size();
        int current = arr[start];
        while(start <= end && end < n){
         
            if(current == target){
                return {start+1,end+1};
            }else if(current > target){
                current -= arr[start];
                if(start == end){
                    ++start;
                    ++end;
                    current += arr[end];
                }else{
                    ++start;
                }
            }else{
                ++end;
                current += arr[end];
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends