#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0;
        int min_steps = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            sum += a[i];
            diff[i] = max(0LL, a[i] - k);
            min_steps += diff[i];
        }

        sort(diff.rbegin(), diff.rend());

        int extra_steps = 0;
        for (int i = 0; i < n; i++) {
            if (sum <= k) {
                break;
            }
            sum -= diff[i];
            extra_steps++;
        }

        cout << min_steps + extra_steps << endl;
    }

    return 0;
}