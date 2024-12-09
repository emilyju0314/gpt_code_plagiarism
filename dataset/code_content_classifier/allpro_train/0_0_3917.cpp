#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int x;
        cin >> x;

        int n = s.length();
        string w(n, '0');

        bool possible = true;
        for (int i = 0; i < n; i++) {
            int left = i - x >= 0 ? s[i - x] - '0' : 0;
            int right = i + x < n ? s[i + x] - '0' : 0;

            if ((left || right) && s[i] == '0') {
                w[i] = '1';
            } else if (!(left || right) && s[i] == '1') {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << endl;
        } else {
            cout << w << endl;
        }
    }

    return 0;
}