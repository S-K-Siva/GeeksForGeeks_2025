//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string findOrder(vector<string> &words) {
        set<char> alphabets;
        int n = words.size();

        // Collect all unique characters
        for(auto &word : words) {
            for(auto ch : word) {
                alphabets.insert(ch);
            }
        }

        // Create character to index mapping
        unordered_map<char, int> charIndex;
        int index = 0;
        for(auto ch : alphabets) {
            charIndex[ch] = index++;
        }

        vector<vector<int>> adj(index);
        vector<int> inDeg(index, 0);

        // Build graph
        for(int i = 0; i < n - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            int len = min(word1.size(), word2.size());

            // Edge case: If word1 is longer but has same prefix, order is invalid
            if (word1.size() > word2.size() && word1.substr(0, len) == word2) {
                return "";
            }

            for(int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[charIndex[word1[j]]].push_back(charIndex[word2[j]]);
                    inDeg[charIndex[word2[j]]]++;
                    break;
                }
            }
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> que;
        for(int i = 0; i < index; i++) {
            if (inDeg[i] == 0) que.push(i);
        }

        string value = "";
        while(!que.empty()) {
            int current = que.front();
            que.pop();
            
            for (auto &entry : charIndex) {
                if (entry.second == current) {
                    value += entry.first;
                    break;
                }
            }

            for(auto neigh : adj[current]) {
                --inDeg[neigh];
                if (inDeg[neigh] == 0) que.push(neigh);
            }
        }

        return (value.size() == alphabets.size()) ? value : "";
    }
};



//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends