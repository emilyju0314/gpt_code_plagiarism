#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                for (int j = 0; j < 26; j++) {
                    int cnt = freq[j] / i * i;
                    if (cnt >= k) {
                        ans = max(ans, i);
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}