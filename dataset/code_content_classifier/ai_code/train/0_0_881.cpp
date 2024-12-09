#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        string s;
        cin >> s;

        long long ans = s.size();
        vector<int> pasteCount(s.size());
        for (int i = 1; i <= s.size(); i++) {
            int pastes = 1;
            int pos = i - 1;
            while (pos < s.size() && pastes <= x) {
                pastes += s[pos] - '1';
                pos++;
            }
            pasteCount[i - 1] = pastes;
        }

        for (int i = 0; i < pasteCount.size(); i++) {
            if (pasteCount[i] == x) break;
            ans = (ans + ((ans - i - 1) * (pasteCount[i] - i - 1)) % MOD) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}