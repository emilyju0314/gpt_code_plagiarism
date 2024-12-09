#include <iostream>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string s, t;
        cin >> s >> t;

        bool possible = true;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] != t[j]) {
                bool found = false;
                for (int k = j + 1; k < s.length(); k++) {
                    if (s[k] == s[j] && t[k] == t[j]) {
                        found = true;
                        swap(s[j], s[k]);
                        break;
                    }
                }
                if (!found) {
                    possible = false;
                    break;
                }
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