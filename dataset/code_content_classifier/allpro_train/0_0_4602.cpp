#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    string t = "";
    int prefixLength = 0;
    int suffixLength = 0;

    for (int i = 1; i < n; i++) {
        if (s.substr(0, i) == s.substr(n - i, i)) {
            prefixLength = i;
        }
    }

    for (int i = 1; i < n - prefixLength; i++) {
        if (s.substr(prefixLength, i) == s.substr(n - i, i)) {
            suffixLength = i;
        }
    }

    if (prefixLength + suffixLength == n && prefixLength > 0) {
        t = s.substr(0, prefixLength);
        cout << t << endl;
    } else {
        cout << "Just a legend" << endl;
    }

    return 0;
}