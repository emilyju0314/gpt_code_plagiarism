#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> prefix_sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i+1] = prefix_sum[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        long double min_vol = prefix_sum[i+1] / static_cast<long double>(i+1);
        long double max_vol = prefix_sum[n] / static_cast<long double>(n);
        cout << min(min_vol, max_vol) << endl;
    }

    return 0;
}