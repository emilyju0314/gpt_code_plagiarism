#include <iostream>
#include <string>

using namespace std;

string addNumbers(string a, string b) {
    string ans = "";
    int carry = 0;
    
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    
    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        
        ans = to_string(sum) + ans;
    }
    
    if (carry > 0) {
        ans = "1" + ans;
    }
    
    return ans;
}

string findB(string a, string s) {
    string b = "0";
    
    while (b.length() < s.length()) {
        string sum = addNumbers(a, b);
        if (sum == s) {
            return b;
        }
        b = addNumbers(b, "1");
    }
    
    return "-1";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a, s;
        cin >> a >> s;
        
        string result = findB(a, s);
        cout << result << endl;
    }
    
    return 0;
}