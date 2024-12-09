#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> ans(n);
    vector<int> pref(n);

    for (int i = 1; i < n; i++) {
        int j = pref[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pref[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pref[i] = j;
    }

    for (int i = 0; i < n; i++) {
        int len = i + 1 - pref[i];
        if (len > i || (len % 2) == 0) {
            ans[i] = -1;
        } else {
            ans[i] = len;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}