#include<bits/stdc++.h>
#define ll long long
#define rep(i, m, n) for (int i = m; i <= n; i++)
#define per(i, m, n) for (int i = m; i >= n; i--)
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn], cnt[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        rep(i, 0, M - 1) cnt[i] = 0;
        rep(i, 1, N) cin >> a[i], cnt[(a[i] % M)]++;
        int ans = (cnt[0] > 0);
        rep(i, 1, M - 1) {
            int x = cnt[i], y = cnt[M - i];
            if (x == 0 && y == 0) continue;
            else ans++;
            if (i == M - i) {
                cnt[i] = 0;
                continue;
            }
            if (x > y) {
                cnt[i] -= (y + 1);
                cnt[M - i] -= y;
            } else if (x < y) {
                cnt[i] -= x;
                cnt[M - i] -= (x + 1);
            } else {
                cnt[i] = 0, cnt[M - i] = 0;
            }
        }
        rep(i, 1, M - 1) ans += cnt[i];
        cout << ans << "\n";
    }
    return 0;
}
