#include <iostream>
#include <string>

using namespace std;

string rotateString(string s, int l, int r, int k) {
    k = k % (r - l + 1);
    string sub = s.substr(l - 1, r - l + 1);
    string rotated = sub.substr(sub.size() - k) + sub.substr(0, sub.size() - k);
    return s.substr(0, l - 1) + rotated + s.substr(r);
}

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        s = rotateString(s, l, r, k);
    }

    cout << s << endl;

    return 0;
}