#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>
#include <unordered_map>
#include <cstring>
#include <map>

#define sz(a) (int)(a).size()
#define all(a) begin(a), end(a)

using namespace std;

using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 1) {
        if ((n - 1) % b == 0) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
        return;
    }
    ll p = 1;
    while (p <= n) {
        if ((n - p) % b == 0) {
            cout << "Yes\n";
            return;
        }
        p *= a;
    }
    cout << "No\n";
}

int main() {
#ifdef LOCAL
    freopen(INPUT_PATH, "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --> 0) {
        solve();
    }

    return 0;
}
