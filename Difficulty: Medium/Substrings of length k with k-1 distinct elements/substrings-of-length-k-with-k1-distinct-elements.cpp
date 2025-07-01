class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.size();
        unordered_map<char,int> track;
        for(int i = 0;i<k;i++){
            ++track[s[i]];
        }
        int res = 0;
        if(track.size() == k-1){
            res++;
        }
        for(int i = k;i<n;i++){
            if(track[s[i-k]] == 1){
                track.erase(s[i-k]);
            }else{
                --track[s[i-k]];
            }
            ++track[s[i]];
            if(track.size() == k-1){
                res++;
            }
        }
        
        return res;
    }
};