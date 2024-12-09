#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int ab = 0, ba = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') {
                ab++;
            } else if (s[i] == 'b' && s[i + 1] == 'a') {
                ba++;
            }
        }

        if (ab == 0 && ba == 0) {
            cout << s << endl;
        } else if (ab > ba) {
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == 'a' && s[i + 1] == 'b') {
                    s[i] = 'b';
                    ab--;
                }
                if (ab == ba) break;
            }
            cout << s << endl;
        } else {
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == 'b' && s[i + 1] == 'a') {
                    s[i] = 'a';
                    ba--;
                }
                if (ab == ba) break;
            }
            cout << s << endl;
        }
    }

    return 0;
}