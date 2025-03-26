//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool helper(int index, set<string>& mpp, string& s, vector<int>& dp) {
        if (index >= s.size()) return true;
        if (dp[index] != -1) return dp[index];
        string substring = "";
        for (int i = index; i < s.size(); i++) {
            substring += s[i];
            if (mpp.count(substring) && helper(i + 1, mpp, s, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        set<string> mpp;
        for (auto word : dictionary) {
            mpp.insert(word);
        }

        vector<int> dp(s.size(), -1);
        return helper(0, mpp, s, dp);
    }
    
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends