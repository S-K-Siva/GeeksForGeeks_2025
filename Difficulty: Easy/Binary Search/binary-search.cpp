class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == k){
                while(mid-1>=0 && arr[mid-1] == k){
                    mid--;
                }
                return mid;
            }
            else if(arr[mid] > k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
};