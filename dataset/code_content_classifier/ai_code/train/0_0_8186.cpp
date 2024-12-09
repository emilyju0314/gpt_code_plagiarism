#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, b, c;
    cin >> n >> k >> b >> c;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    long long ans = LLONG_MAX;
    long long pref_sum = 0;
    long long cost_blog = 0;
    
    for (int i = 0; i < n; i++) {
        pref_sum += t[i];
        if (i >= k - 1) {
            ans = min(ans, cost_blog + (long long)i * c - pref_sum);
            if (i < n - 1) {
                cost_blog += b * (t[i + 1] - t[i]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}