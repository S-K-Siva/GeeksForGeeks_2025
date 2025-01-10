class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int> freq;
        int n = arr.size();
        for(int i = 0;i<k && i < n;i++){
            ++freq[arr[i]];
        }
        vector<int> result;
        result.push_back(freq.size());
        int j = 0;
        for(int i = k;i<n;i++){
            ++freq[arr[i]];
            if(freq[arr[j]] == 1)
                freq.erase(arr[j]);
            else 
                --freq[arr[j]];
            ++j;
            result.push_back(freq.size());
        }
        return result;
    }
};
