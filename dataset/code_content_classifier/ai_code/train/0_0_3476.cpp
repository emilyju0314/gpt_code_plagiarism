#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string stairs;
        cin >> stairs;

        int ans = 0;

        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + (stairs[i-1] == '1');
        }

        for (int i = 0; i <= n; i++) {
            ans = max(ans, max(prefix[i], i - prefix[i]) + min(prefix[n] - prefix[i], n - i - (prefix[n] - prefix[i])));
        }

        cout << ans << endl;
    }

    return 0;
}