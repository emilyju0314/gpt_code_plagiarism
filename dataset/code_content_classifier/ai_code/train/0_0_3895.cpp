#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkPeriod(string& s, int l, int r, int t) {
    for (int i = 0; i < r - l + 1 - t; i++) {
        if (s[l + i] != s[l + i + t]) {
            return false;
        }
    }
    return true;
}

int main() {
    string S;
    int Q;
    cin >> S;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int l, r, t;
        cin >> l >> r >> t;

        if (checkPeriod(S, l - 1, r - 1, t)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}