class Solution {
  public:
    int romanToDecimal(string &s) {
        int result = 0;
        
        unordered_map<char,int> data;
        data['I'] = 1;
        data['V'] = 5;
        data['X'] = 10;
        data['L'] = 50;
        data['C'] = 100;
        data['D'] = 500;
        data['M'] = 1000;
        int i = 0;
        while(i<s.size()){
            if(s[i] == 'M'){
                result += 1000;
                i++;
                continue;
            }
            if(i+1 < s.size()){
                if(s[i] == 'I' && s[i+1] == 'X'){
                    result += 9;
                    i+=2;
                    continue;
                }else if(s[i] == 'X' && s[i+1] == 'L'){
                    result += 40;
                    i+=2;
                    continue;
                }else if(s[i] == 'C' && s[i+1] == 'M'){
                    result += 900;
                    i+=2;
                    continue;
                }else if(s[i] == 'C' && s[i+1] == 'D'){
                    result += 400;
                    i+=2;
                    continue;
                }else if(s[i] == 'I' && s[i+1] == 'V'){
                    result += 4;
                    i+=2;
                    continue;
                }else if(s[i] == 'X' && s[i+1] == 'C'){
                    result += 90;
                    i+=2;
                    continue;
                }else if(s[i] == 'V' && s[i+1] == 'I'){
                    result += 6;
                    i+=2;
                    continue;
                }else{
                    result += data[s[i]];
                    i++;
                    continue;
                }
            }else{
                result += data[s[i]];
                i++;
            }
        }
        return result;
    }
};