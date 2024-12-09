#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addNumbers(string a, string b) {
    string result = "";
    int carry = 0;
    
    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }
    
    for (int i = a.length()-1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }
    
    if (carry > 0) {
        result = to_string(carry) + result;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a, s;
        cin >> a >> s;
        
        string b = "0";
        string temp = a;
        while (b.length() <= s.length()) {
            if (addNumbers(a, b) == s) {
                cout << b << endl;
                break;
            }
            b = addNumbers("1" + b, temp);
        }
        
        if (b.length() > s.length()) {
            cout << -1 << endl;
        }
    }
    
    return 0;
}