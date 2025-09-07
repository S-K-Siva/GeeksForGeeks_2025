class Solution {
  public:
    int reverseExponentiation(int n) {
        int number = n;
        int reverse = 0;
        
        while(number != 0){
            reverse = reverse * 10 + (number%10);
            number/=10;
        }
        return pow(n,reverse);
    }
};