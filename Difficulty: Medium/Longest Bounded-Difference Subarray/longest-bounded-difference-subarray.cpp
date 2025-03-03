//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
   public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> mini, maxi;
        int s = 0, element = 0;
        int ansStart = 0, ansEnd = 0;
        vector<int> res;
        int n = arr.size();
        
        while (element < n) {
            while (!mini.empty() && arr[mini.back()] > arr[element]) mini.pop_back();
            while (!maxi.empty() && arr[maxi.back()] < arr[element]) maxi.pop_back();
            
            mini.push_back(element);
            maxi.push_back(element);
            
            while (arr[maxi.front()] - arr[mini.front()] > x) {
                if (s == maxi.front()) maxi.pop_front();
                if (s == mini.front()) mini.pop_front();
                s++;
            }
            
            if (element - s > ansEnd - ansStart) {
                ansEnd = element;
                ansStart = s;
            }
            element++;
        }
        
        for (int i = ansStart; i <= ansEnd; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }

};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends