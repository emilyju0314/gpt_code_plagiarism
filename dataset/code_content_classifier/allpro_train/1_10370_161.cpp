#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

bool cmp(pii a, pii b) {
    return 1ll * a.first * (b.second + 1) > 1ll * b.first * (a.second + 1);
}

int main() {
    ios::sync_with_stdio(false);
    int n, z = 0;
    ll t, d[42] = {};
    vector<int> b;
    for (int i = 1; i <= 40; i++) d[i] = mod;
    pii a[200005] = {};
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) if (a[i].first) {
        for (int j = 40; j; j--) {
            d[j] = min(d[j], d[j - 1] + 1 + (d[j - 1] + 1) * a[i].first + a[i].second);
        }
    }
    //for (int i = 0; i <= 10; i++) cout << d[i] << ' '; cout << '\n';
    for (int i = 1; i <= n; i++) if (!a[i].first) b.push_back(a[i].second);
    sort(b.begin(), b.end());
    for (int i = 0; i <= 40; i++) if (d[i] <= t) {
        int y = i;
        for (int j = 0; j < b.size(); j++) {
            if (d[i] + b[j] + 1 <= t) d[i] += b[j] + 1, y++;
            else break;
        }
        z = max(z, y);
    }
    cout << z;
}
