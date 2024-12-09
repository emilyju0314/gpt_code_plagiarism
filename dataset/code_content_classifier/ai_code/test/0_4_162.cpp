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

        vector<long long> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        long long ans = h[n-1]; // Initialize answer with the last heap's stones

        for (int i = n-2; i >= 0; i--) {
            ans = max(ans, (h[i] + ans) / 2); // Calculate the maximum stones in each heap
        }

        cout << ans << endl;
    }

    return 0;
}