// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        map<string,vector<string>> track;
        
        
        for(auto str : arr){
            string t = str;
            sort(t.begin(),t.end());
            if(track.find(t) == track.end()){
                track[t] = {str};
            }else{
                track[t].push_back(str);
            }
        }
        
        vector<vector<string>> res;
        for(auto it : track){
            res.push_back(it.second);
        }
        return res;
    }
};