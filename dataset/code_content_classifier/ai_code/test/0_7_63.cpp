#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isRegularBracketSequence(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) {
            return false;
        }
    }

    return balance == 0;
}

int main() {
    int n;
    cin >> n;

    string s;
    int openCount = 0, res = 0;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (isRegularBracketSequence(s)) {
            res += count(s.begin(), s.end(), ')');
            openCount += count(s.begin(), s.end(), '(') - count(s.begin(), s.end(), ')');
        } else {
            openCount += count(s.begin(), s.end(), '(') - count(s.begin(), s.end(), ')');
        }
    }

    if (openCount == 0) {
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}