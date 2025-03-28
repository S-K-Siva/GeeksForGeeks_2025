//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        vector<pair<int,int>> timing;
        
        for(int i = 0;i<start.size();i++){
            timing.push_back({start[i],finish[i]});
        }
        
        sort(timing.begin(),timing.end(),[&](pair<int,int> a, pair<int,int>b){
            return a.second < b.second;
        });
        
        int count = 1;
        int finish_time = timing[0].second;
        
        for(int i = 1;i<start.size();i++)
        {
            if(timing[i].first > finish_time){
                finish_time = timing[i].second;
                count++;
            }
        }
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends