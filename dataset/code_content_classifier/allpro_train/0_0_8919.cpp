#include <iostream>
#include <string>

using namespace std;

bool matchStrings(string s, string t) {
    if (s == t) return true;
    if (s.find('*') == string::npos) return false;

    int wildcardPos = s.find('*');
    if (wildcardPos == 0) {
        string suffix = s.substr(1);
        return (t.length() >= suffix.length() && t.substr(t.length() - suffix.length()) == suffix);
    } else {
        string prefix = s.substr(0, wildcardPos);
        string suffix = s.substr(wildcardPos + 1);

        if (t.length() < prefix.length() + suffix.length()) return false;

        if (t.substr(0, prefix.length()) == prefix && t.substr(t.length() - suffix.length()) == suffix) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if (matchStrings(s, t)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}