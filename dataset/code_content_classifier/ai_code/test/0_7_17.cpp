#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Calculate the prefix sums
        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + a[i-1];
        }

        // Calculate the suffix sums
        vector<int> suff(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            suff[i] = suff[i+1] + a[i];
        }

        int ans = n-1; // Initialize ans to maximum possible inversions

        // Find the minimum number of inversions
        for(int i = 0; i < n; i++) {
            int inversions = i + 1 - pref[i+1] - (n - i - 1) + suff[i];
            ans = min(ans, inversions);
        }

        cout << ans << endl;
    }

    return 0;
}