class Solution {
  public:
    bool isValid(vector<vector<int>>& arr) {
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            unordered_map<int,int> row;
            unordered_map<int,int> col;
            for(int j= 0;j<n;j++){
                if(row[arr[i][j]] && arr[i][j] != 0) return false;
                if(col[arr[j][i]] && arr[j][i] != 0) return false;
                row[arr[i][j]]++;
                col[arr[j][i]]++;
            }
        }
        for(int i = 0;i<n;i+=3){
            unordered_map<int,int> box;
            for(int j = 0;j<3;j++){
                for(int k = 0;k<3;k++){
                    if(box[arr[i+j][i+k]] && arr[i+j][i+k] != 0)return false;
                    box[arr[i+j][i+k]]++;
                }
            }
        }
        return true;
    }
};