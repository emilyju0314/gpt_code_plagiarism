#include <iostream>
#include <string>

using namespace std;

string addLeadingZeros(string num, int len) {
    if (num.size() < len) {
        int zerosToAdd = len - num.size();
        string zeros(zerosToAdd, '0');
        return zeros + num;
    }
    return num;
}

string calculateB(string a, string s) {
    int len = max(a.size(), s.size());
    a = addLeadingZeros(a, len);
    s = addLeadingZeros(s, len);

    string b = "";
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int diff = s[i] - a[i] - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        b = to_string(diff) + b;
    }
    
    return b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, s;
        cin >> a >> s;

        string b = calculateB(a, s);

        if (b[0] == '0') {
            cout << "-1" << endl;
        } else {
            cout << b << endl;
        }
    }

    return 0;
}