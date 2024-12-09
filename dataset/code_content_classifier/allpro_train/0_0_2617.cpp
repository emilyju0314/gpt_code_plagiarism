#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        int m;
        cin >> m;

        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string t(m, '_');
        for (char c = 'z'; c >= 'a'; c--) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == c) {
                    int current_b = 0;
                    for (int j = 0; j < m; j++) {
                        current_b += abs(i - j) * (s[j] > c);
                    }
                    if (current_b == b[m - 1]) {
                        t[b[m - 1]] = c;
                        break;
                    }
                }
            }
        }

        cout << t << endl;
    }

    return 0;
}