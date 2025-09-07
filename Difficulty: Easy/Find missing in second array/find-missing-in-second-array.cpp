class Solution {

  public:
    vector<int> findMissing(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> freq;
        for(int i = 0;i<b.size();i++){
            ++freq[b[i]];
        }
        vector<int> res;
        for(int i = 0;i<a.size();i++){
            if(!freq[a[i]]){
                res.push_back(a[i]);
            }
        }
        return res;
    }
};
