#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int slen = s.size();
    int tlen = t.size();

    // Check if t is a substring of s
    if (s.find(t) == string::npos) {
        cout << 0 << endl;
        return 0;
    }

    // Check if t is a repeating substring of s
    bool repeating = true;
    for (int i = 0; i < slen; i++) {
        if (s[i] != t[i % tlen]) {
            repeating = false;
            break;
        }
    }

    if (repeating) {
        cout << -1 << endl;
    } else {
        if (s.size() % t.size() == 0) {
            cout << s.size() / t.size() << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}