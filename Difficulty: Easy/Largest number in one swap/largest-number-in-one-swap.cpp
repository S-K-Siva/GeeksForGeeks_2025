class Solution {
  public:
    string largestSwap(string &s) {
        
        vector<int> lastIndex(10, -1);
        
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i] - '0'] = i;
        }
        
        for(int i = 0; i < s.size(); i++){
            int digit = s[i] - '0';
            
            for(int d = 9; d > digit; d--){
                if(lastIndex[d] > i){
                    swap(s[i], s[lastIndex[d]]);
                    return s;
                }
            }
        }
        
        return s;
    }
};