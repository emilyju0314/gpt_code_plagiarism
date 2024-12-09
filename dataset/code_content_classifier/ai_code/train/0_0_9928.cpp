#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, l, r;
    cin >> a >> b >> l >> r;

    string s = "";
    int n = a + b;
    int m = r - l + 1;
    
    vector<int> cnt(a, 0);
    for (int i = 0; i < a; i++) {
        s += 'a' + i;
    }

    for (int i = 0; i < m; i++) {
        cnt[(l + i - 1) % a]++;
    }

    int diff = 0;
    for (int i = 0; i < a; i++) {
        if (cnt[i] == 0) {
            diff++;
        }
    }

    int ans = diff;
    for (int i = 1; i < (1 << a); i++) {
        string t = "";
        int d = 0;
        for (int j = 0; j < a; j++) {
            if ((i >> j) & 1) {
                t += 'a' + j;
                d++;
            }
        }

        int cnta = 0, cntb = 0;
        for (int j = 0; j < t.length(); j++) {
            if (cnt[(l + j - 1) % a] == 1 && t.find(s[(l + j - 1) % n]) == string::npos) {
                cnta++;
            }
            if (cnt[(l + j - 1) % a] == 0 && t.find(s[(l + j - 1) % n]) == string::npos) {
                cntb++;
            }
        }

        ans = min(ans, diff - cnta + cntb);
    }

    cout << ans << endl;

    return 0;
}