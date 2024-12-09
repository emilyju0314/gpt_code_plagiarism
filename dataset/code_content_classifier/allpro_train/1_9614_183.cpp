#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int D, E;
void solve() {
    double ans = 1e8;
    rep(y, 101) rep(x, 101) {
        if (x + y != D) continue;

        ans = min(ans, abs(sqrt(x * x + y * y) - E));
    }
    printf("%.20f\n", ans);
}
int main() {
    while (cin >> D >> E, E) {
        solve();
    }

    return 0;
}