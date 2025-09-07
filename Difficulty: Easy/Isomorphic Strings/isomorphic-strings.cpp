class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        
        unordered_map<char,char> track1,track2;
        
        for(int i = 0;i<s1.size();i++){
            if(track1[s1[i]] && track1[s1[i]] != s2[i] ||
            track2[s2[i]] && track2[s2[i]] != s1[i]) return false;
            
            track1[s1[i]] = s2[i];
            track2[s2[i]] = s1[i];
            
        }
        return true;
    }
};