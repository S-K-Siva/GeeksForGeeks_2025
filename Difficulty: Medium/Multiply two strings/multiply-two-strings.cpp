//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    // long long int getNumber(string s){
    //     long long int number = 0;
    //     for(long long int i = 0;i<s.size();i++){
    //         if(s[i] == '-') continue;
    //         long long int val = s[i] - '0';
    //         number = (number * 10) + val;
    //     }
    //     return number;
    // }
    // string multiplyStrings(string& s1, string& s2) {
    //     bool neg1 = false, neg2 = false;
    //     if(s1[0] == '-') neg1 = true;
    //     if(s2[0] == '-') neg2 = true;
    //     long long int num1 = getNumber(s1);
    //     long long int num2 = getNumber(s2);
    //     if(neg1) num1 *= -1;
    //     if(neg2) num2 *= -1;
    //     long long int mul=num1*num2;
    //     return to_string(mul);
    // }
    
    bool isZero(string& s) {
    for (char c : s) {
        if (c != '0') return false;
    }
    return true;
}

string multiplyStrings(string& num1, string& num2) {
    if (isZero(num1) || isZero(num2)) return "0";

    bool neg = false;
    if (num1[0] == '-') {
        neg = !neg;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        neg = !neg;
        num2 = num2.substr(1);
    }

    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string ans = "";
    int i = 0;
    while (i < result.size() && result[i] == 0) i++;

    for (; i < result.size(); i++) {
        ans.push_back(result[i] + '0');
    }

    if (neg) ans = "-" + ans;
    return ans;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends