#include <iostream>
#include <string>
using namespace std;

bool isValid(string a, string b, string s) {
    int n = a.length();
    int m = b.length();
    
    if (n > m) {
        return false;
    }
    
    string res;
    int carry = 0;
    for (int i = n-1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i+m-n] - '0') + carry;
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }
    
    if (carry > 0) {
        res = to_string(carry) + res;
    }
    
    if (res != s.substr(m-n)) {
        return false;
    }
    
    return true;
}

string findB(string a, string s) {
    string b = "";
    for (int i = 0; i <= 9; i++) {
        b = to_string(i) + b;
        if (isValid(a, b, s)) {
            return b;
        }
    }
    return "-1";
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string a, s;
        cin >> a >> s;
        
        string b = findB(a, s);
        cout << b << endl;
    }
    
    return 0;
}