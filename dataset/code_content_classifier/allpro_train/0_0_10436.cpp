#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;

    string title = s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (s[n - i - 1] != '?') {
                title[i] = title[n - i - 1];
            }
        } else {
            title[n - i - 1] = title[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            for (char ch = 'a'; ch < 'a' + k; ch++) {
                if (ch == title[i] || ch == title[n - i - 1]) continue;
                title[i] = title[n - i - 1] = ch;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (title[i] != title[n - i - 1]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        } else if (title[i] == '?' && i == n - i - 1) {
            title[i] = 'a';
        }
    }

    cout << title << endl;

    return 0;
}