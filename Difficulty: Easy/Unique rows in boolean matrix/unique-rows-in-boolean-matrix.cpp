class Solution {
  public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        vector<vector<int>> unique;
        unordered_map<string,int> track;
        for(int i = 0;i<row;i++){
            vector<int> rowValues;
            string val = "";
            for(int j = 0;j<col;j++){
                if(M[i][j] == 0) val += '0';
                else val += '1';
                rowValues.push_back(M[i][j]);
            }
            if(!track[val]){
                unique.push_back(rowValues);
                ++track[val];
            }
        }
        return unique;
    }
};