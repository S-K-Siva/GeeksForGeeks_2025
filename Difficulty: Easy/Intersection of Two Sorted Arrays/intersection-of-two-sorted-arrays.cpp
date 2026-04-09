class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        
        vector<int> result;
        set<int> s1,s2;
        for(auto it : a){
            s1.insert(it);
        }
        for(auto it : b){
            s2.insert(it);
        }
        unordered_map<int,int> track;
        for(auto it : s1){
            track[it]++;
        }
        for(auto it : s2){
            if(track.find(it) != track.end()){
                result.push_back(it);
            }
        }
        return result;
    }
};