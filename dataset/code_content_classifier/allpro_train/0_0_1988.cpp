#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int l, d;
        cin >> l >> d;

        if (l == 0 && d == 0) {
            break;
        }

        vector<string> str(3);
        for (int i = 0; i < 3; i++) {
            cin >> str[i];
        }

        string ans = "";
        bool found = false;

        for (int i = 0; i < l && !found; i++) {
            char original_char = str[0][i];
            for (char c = 'A'; c <= 'Z'; c++) {
                str[0][i] = c;
                int count = 0;

                for (int j = 1; j < 3; j++) {
                    int diff = 0;
                    for (int k = 0; k < l; k++) {
                        if (str[0][k] != str[j][k]) {
                            diff++;
                        }
                    }
                    if (diff > d) {
                        count++;
                        break;
                    }
                }

                if (count == 0) {
                    ans += c;
                    found = true;
                    break;
                }
            }

            str[0][i] = original_char;
        }

        if (found) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}