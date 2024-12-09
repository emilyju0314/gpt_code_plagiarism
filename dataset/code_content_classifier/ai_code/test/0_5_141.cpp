#include <iostream>
#include <string>

using namespace std;

long long getSum(long long a, long long b) {
    string sa = to_string(a);
    string sb = to_string(b);
    
    int len = max(sa.length(), sb.length());
    
    if (sa.length() < len) {
        sa = string(len - sa.length(), '0') + sa;
    }
    if (sb.length() < len) {
        sb = string(len - sb.length(), '0') + sb;
    }
    
    string result = "";
    int carry = 0;
    for (int i = len-1; i >= 0; i--) {
        int sum = (sa[i] - '0') + (sb[i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }
    
    if (carry > 0) {
        result = to_string(carry) + result;
    }
    
    return stoll(result);
}

long long findB(long long a, long long s) {
    if (a > s) return -1;
    
    for (long long b = 1; b < s; b++) {
        if (getSum(a, b) == s) {
            return b;
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long a, s;
        cin >> a >> s;
        
        long long b = findB(a, s);
        cout << b << endl;
    }
    
    return 0;
}