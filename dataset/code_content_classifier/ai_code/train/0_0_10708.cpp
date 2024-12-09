#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int count = upper_bound(a.begin(), a.end(), a[i] - 1 + k*x) - lower_bound(a.begin(), a.end(), a[i]);
        ans += count;
    }

    cout << ans << endl;

    return 0;
}