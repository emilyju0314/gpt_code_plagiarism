#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool possible = true;

        if (s[0] == 'N' || s[s.length() - 1] == 'N' || s.length() == 1) {
            possible = false;
        }

        for (int i = 1; i < s.length() - 1; i++) {
            if (s[i] == 'N' && s[i + 1] == 'N') {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}