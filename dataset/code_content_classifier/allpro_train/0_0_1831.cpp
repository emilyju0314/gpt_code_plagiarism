#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minMoves(string s, string t) {
    for (int i = 0; i < s.length(); i++) {
        if (s == t) {
            return i;
        }
        if (s[i] == t[i]) {
            continue;
        }
        int idx = s.find(t[i]);
        if (idx == -1) {
            return -1;
        }
        if (idx < i) {
            rotate(s.begin() + idx, s.begin() + idx + 1, s.begin() + i + 1);
        } else {
            rotate(s.begin() + i, s.begin() + idx + 1, s.begin() + idx + 2);
        }
    }
    return s == t ? s.length() - 1 : -1;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int moves = minMoves(s, t);
        cout << moves << endl;
    }

    return 0;
}