#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;
    int lr_diff = 0;
    int ud_diff = 0;

    for (char c : s) {
        if (c == 'L') {
            lr_diff--;
        } else if (c == 'R') {
            lr_diff++;
        } else if (c == 'U') {
            ud_diff++;
        } else if (c == 'D') {
            ud_diff--;
        }
    }

    if ((abs(lr_diff) + abs(ud_diff)) % 2 != 0) {
        cout << -1 << endl;
    } else {
        int edits_lr = abs(lr_diff) / 2;
        int edits_ud = abs(ud_diff) / 2;

        count = edits_lr + edits_ud;

        cout << count << endl;
    }

    return 0;
}