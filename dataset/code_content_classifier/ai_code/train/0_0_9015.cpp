#include <iostream>
#include <string>

using namespace std;

bool canPrint(string s, string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] != t[j]) {
            return false;
        }
        char cur = s[i];
        int cnt_s = 0, cnt_t = 0;
        while (i < s.length() && s[i] == cur) {
            cnt_s++;
            i++;
        }
        while (j < t.length() && t[j] == cur) {
            cnt_t++;
            j++;
        }
        if (cnt_t < cnt_s) {
            return false;
        }
    }
    return j == t.length();
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        if (canPrint(s, t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}