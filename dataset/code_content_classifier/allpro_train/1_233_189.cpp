#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    rep(i, n) cin >> p[i];

    int ans = 0;
    rep(i, n) {
        if (p[i] == i + 1) swap(p[i], p[i + 1]), ans++;
    }

    cout << ans << endl;
    return 0;
}
