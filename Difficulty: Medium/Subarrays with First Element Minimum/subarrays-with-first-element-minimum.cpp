// class Solution {
//   public:
//     int countSubarrays(vector<int> &arr) {
//         int cnt = 0;
//         int n = arr.size();
        
//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
                
//                 bool possible = true;
                
//                 for(int k = i + 1; k <= j; k++){
//                     if(arr[k] < arr[i]){
//                         possible = false;
//                         break;
//                     }
//                 }
                
//                 if(possible) cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };
class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        long long cnt = 0;
        
        for(int i = n - 1; i >= 0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            int nextSmaller;
            
            if(st.empty()) nextSmaller = n;
            else nextSmaller = st.top();
            
            cnt += (nextSmaller - i);
            
            st.push(i);
        }
        
        return cnt;
    }
};