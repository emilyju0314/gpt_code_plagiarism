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
            if (s[i] == 'a' && s[i+1] == 'b') ab++;
            if (s[i] == 'b' && s[i+1] == 'a') ba++;
        }

        if (ab == 0 && ba == 0) {
            cout << s << endl;
        } else if (ab == ba) {
            cout << s << endl;
        } else if (ab > ba) {
            for (char &c : s) {
                if (c == 'a') c = 'b';
            }
            cout << s << endl;
        } else {
            for (char &c : s) {
                if (c == 'b') c = 'a';
            }
            cout << s << endl;
        }
    }

    return 0;
}