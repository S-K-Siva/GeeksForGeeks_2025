class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int candidate = 0;
        int n = mat.size();
        for(int i = 1;i<n;i++){
            if(mat[candidate][i]) candidate = i;
        }
        
        for(int i = 0;i<n;i++){
            if(i != candidate){
                if(mat[candidate][i] == 1 || mat[i][candidate] == 0) return -1;
            }
        }
        return candidate;
        // WA
        
        // int n = mat.size();
        // unordered_map<int,vector<int>> track;
        
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         if(mat[i][j] == 1){
        //             track[i].push_back(j);
        //         }
        //     }
        // }
        // for(int i = 0;i<n;i++){
        //     if(track[i].size() == 1) return i;
        // }
        // return -1;
    }
};