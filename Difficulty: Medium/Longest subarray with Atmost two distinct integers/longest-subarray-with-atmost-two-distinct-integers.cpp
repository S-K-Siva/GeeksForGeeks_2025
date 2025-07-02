class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int left = 0;
        int right = 0;
        int n = arr.size();
        int result = 0;
        unordered_map<int,int> track;
        while(left <= right && right < n){
            ++track[arr[right++]];
            if(track.size() <= 2){
                result = max(result, right - left);
            }else{
                if(track[arr[left]] == 1){
                    track.erase(arr[left]);
                }else{
                    --track[arr[left]];
                }
                ++left;
            }
        }
        return result;
    }
};