#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;

        vector<char> layout(26, ' ');
        bool possible = true;

        layout[s[0] - 'a'] = 'a';
        for (int i = 1; i < s.size(); i++) {
            if (layout[s[i] - 'a'] != ' ' && layout[s[i] - 'a'] != layout[s[i - 1] - 'a']) {
                possible = false;
                break;
            }
            layout[s[i] - 'a'] = layout[s[i - 1] - 'a'];
        }

        if (possible) {
            cout << "YES" << endl;
            vector<char> remainingChars;
            for (char c = 'a'; c <= 'z'; c++) {
                if (layout[c - 'a'] == ' ') {
                    remainingChars.push_back(c);
                }
            }

            int idx = 0;
            for (int i = 0; i < 26; i++) {
                if (layout[i] == ' ') {
                    layout[i] = remainingChars[idx++];
                }
            }

            for (int i = 0; i < 26; i++) {
                cout << layout[i];
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}