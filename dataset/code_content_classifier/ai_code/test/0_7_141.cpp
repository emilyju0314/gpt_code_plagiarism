#include <iostream>
#include <string>

using namespace std;

string addNumbers(string a, string b) {
    int n = a.size();
    int m = b.size();
    if (n < m) {
        a = string(m - n, '0') + a;
    } else if (m < n) {
        b = string(n - m, '0') + b;
    }

    int carry = 0;
    string result = "";
    for (int i = n - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }

    if (carry > 0) {
        result = to_string(carry) + result;
    }
    return result;
}

string findB(string a, string s) {
    string b = "";
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        string new_a = a.substr(i);
        string new_s = s.substr(0, a.size() - i);
        if (new_a.size() > new_s.size()) {
            b = addNumbers(new_a, s);
            if (b >= s) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        return b;
    } else {
        return "-1";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, s;
        cin >> a >> s;
        string b = findB(a, s);
        cout << b << endl;
    }
    
    return 0;
}