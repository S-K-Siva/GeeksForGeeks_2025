class Solution {
  public:
    vector<string> findPermutation(string &s) {
        set<string> result;
        sort(s.begin(),s.end());
        do{
            result.insert(s);
        }while(next_permutation(s.begin(),s.end()));
        
        vector<string>ss(result.begin(),result.end());
        return ss;
    }
};
