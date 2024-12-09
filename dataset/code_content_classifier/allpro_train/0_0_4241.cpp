#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isValid(string p, int w, string s) {
    for (int t = 1; t <= s.length(); t++) {
        for (int x = 0; x < s.length(); x++) {
            int sum = 0;
            for (int i = -w; i <= w; i++) {
                if (x + i >= 0 && x + i < s.length()) {
                    sum += (p[(w + i)] - '0') * (1 << (w + i));
                }
            }
            if (p[x] != s[x]) {
                return false;
            }
        }
    }
    return true;
}

string findP(int w, string s) {
    string p = string(22*w + 1, '0');
    while (!isValid(p, w, s)) {
        bool carry = true;
        for (int i = p.length() - 1; i >= 0 && carry; i--) {
            if (p[i] == '0') {
                p[i] = '1';
                carry = false;
            } else {
                p[i] = '0';
            }
        }
        if (carry) {
            return "no";
        }
    }
    return p;
}

int main() {
    int w;
    string s;
    cin >> w >> s;

    string result = findP(w, s);
    cout << result << endl;

    return 0;
}