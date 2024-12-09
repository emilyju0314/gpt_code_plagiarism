#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'c'; c++) {
                    if ((i == 0 || s[i-1] != c) && (i == s.length()-1 || s[i+1] != c)) {
                        s[i] = c;
                        break;
                    }
                }
            }
        }

        bool beautiful = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) {
                beautiful = false;
                break;
            }
        }

        if (beautiful) {
            cout << s << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}