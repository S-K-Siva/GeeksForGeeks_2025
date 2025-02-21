//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    void insertValue(int x){
        if(maxHeap.size() == 0){
            maxHeap.push(x);
            return;
        }else if(maxHeap.size() > minHeap.size()){
            if(x < maxHeap.top()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }else{
                minHeap.push(x);
            }
        }else{
            if(x < maxHeap.top()){
                maxHeap.push(x);
            }else{
                minHeap.push(x);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        return;
    }
    double getMedianValue(){
        if(maxHeap.size() == minHeap.size()){
            return (double) (maxHeap.top() + minHeap.top())/2.0;
        }else{
            return maxHeap.top();
        }
    } 
    
    vector<double> getMedian(vector<int> &arr) {
       
        vector<double> result;
        
        for(int i = 0;i<arr.size();i++){
            insertValue(arr[i]);
            result.push_back(getMedianValue());
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends