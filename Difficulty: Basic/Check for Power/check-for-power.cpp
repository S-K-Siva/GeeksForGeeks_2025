class Solution {
  public:
    int isPowerOfAnother(int x, int y) {
        // code here
        for(int i = 0;i<=y;i++){
            if(pow(x,i) == y) return true;
        }
        return false;
    }
};