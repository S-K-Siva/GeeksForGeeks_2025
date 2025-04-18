//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Trie {
private:
    unordered_map<string, int> mpp;

public:
    Trie() {
        // Constructor initializes an empty map
    }

    void insert(string &word) {
        // Insert word into Trie (map)
        mpp[word]++;
    }

    bool search(string &word) {
        // Search for exact word
        return mpp.find(word) != mpp.end();
    }

    bool isPrefix(string &prefix) {
        // Check if any word starts with the given prefix
        for (auto entry : mpp) {
            if (entry.first.find(prefix) == 0) { // starts with prefix
                return true;
            }
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends