class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int left,right;
    left = right = 0;
    int result = -1;
    map<char,int> vals;
    while (right < s.size()){
        if(!vals[s[right]]){
            vals[s[right]] = 1;
        }else{
            vals[s[right]]++;
        }
        while (vals.size() > k){
            
            --vals[s[left]];
            if (vals[s[left]] == 0){
                vals.erase(s[left]);
            }
            ++left;
        }
        if(vals.size() == k){
            result = max(result,right - left + 1);
        }
        ++right;
    }
    return result;
        
    }
};