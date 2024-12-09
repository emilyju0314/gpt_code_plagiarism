#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

string replace_question_marks(int a, int b, string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            a--;
        } else if (s[i] == '1') {
            b--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i == n - i - 1) {
                if (a % 2 == 1) {
                    s[i] = '0';
                    a--;
                }
            } else {
                if (a >= 2) {
                    s[i] = '0';
                    s[n - i - 1] = '0';
                    a -= 2;
                } else if (b >= 2) {
                    s[i] = '1';
                    s[n - i - 1] = '1';
                    b -= 2;
                } else {
                    return "-1";
                }
            }
        }
    }

    if (is_palindrome(s) && a == 0 && b == 0) {
        return s;
    } else {
        return "-1";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        string s;
        cin >> s;

        string result = replace_question_marks(a, b, s);

        cout << result << endl;
    }

    return 0;
}