#include <iostream>
#include <string>
using namespace std;

string findNumberB(string a, string s) {
    string b = "";
    int b_len = s.length() - a.length();
    
    // Step 1: Fill leading zeros if needed
    for(int i = 0; i < b_len; i++) {
        b += '0';
    }
    
    // Step 2-4: Calculate the value of b
    int carry = 0; // Initialize the carry to 0
    for(int i = a.length()-1; i >= 0; i--) {
        int sum = (a[i] - '0') + (s[i+b_len] - '0') + carry;
        b = to_string(sum % 10) + b;
        carry = sum / 10;
    }
    
    // Check if any remaining carry that cannot be accommodated in previous step
    if(carry != 0) {
        return "-1"; // No suitable number b exists
    }
    
    return b;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        string a, s;
        cin >> a >> s;
        string numberB = findNumberB(a, s);
        cout << numberB << endl;
    }
    
    return 0;
}