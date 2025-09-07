class Solution {
  public:
    int maxWater(vector<int> &arr) {
        if(arr.size() < 3) return 0;
        int n = arr.size();
        vector<int> left(n),right(n);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i = 1;i<n;i++){
            left[i] = max(arr[i],left[i-1]);
        }
        for(int i = n-2;i>=0;i--){
            right[i] = max(arr[i],right[i+1]);
        }
        
        int result= 0;
        for(int i = 0;i<n;i++){
            result += min(left[i],right[i]) - arr[i];
        }
        return result;
        
    }
};