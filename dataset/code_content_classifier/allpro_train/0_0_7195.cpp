#include <iostream>
#include <string>

using namespace std;

bool isValidPhoneNumber(string s) {
    if (s.length() != 11 || s[0] != '8') {
        return false;
    }
    for (int i = 0; i < 11; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (n < 11) {
            cout << "NO" << endl;
        } else {
            bool found = false;
            for (int i = 0; i <= n-11; i++) {
                string sub = s.substr(i, 11);
                if (isValidPhoneNumber(sub)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}