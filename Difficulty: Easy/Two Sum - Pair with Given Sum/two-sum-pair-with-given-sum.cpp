class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        
        unordered_map<int,int> track;
        for(int i = 0;i<arr.size();i++){
            if(track[target - arr[i]]) return true;
            track[arr[i]]++;
        }
        return false;
    }
};