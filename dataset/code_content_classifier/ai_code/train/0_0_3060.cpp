#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i] - 1;
        int y = a[i] + 1;

        if (x >= 1) {
            ans += ((long long) x * (m - y + 1));
        }

        if (y <= m) {
            ans += ((long long) (y - 1) * (m - y + 1));
        }

        ans += (m - 1);
    }

    cout << ans << endl;

    return 0;
}