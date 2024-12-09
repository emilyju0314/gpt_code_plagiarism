#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        string a, b;

        int open = 0;
        int close = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                a += (open < n/2) ? '(' : ')';
                b += (open < n/2) ? '(' : ')';
                open++;
            } else {
                a += (close < n/2) ? '(' : ')';
                b += (close < n/2) ? ')' : '(';
                close++;
            }
        }

        // Check if the bracket sequences are balanced
        int balance = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '(') balance++;
            else balance--;
            if (balance < 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
            cout << a << endl;
            cout << b << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}