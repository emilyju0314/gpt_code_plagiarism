#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  vi d(n);
  REP(i, n) { cin >> d[i]; }

  vi c(13);
  REP(i, n) {
    c[d[i]]++;
    if (d[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  vi a;
  a.push_back(0);
  a.push_back(24);
  int use = 1;
  REP(i, 13) {
    if (c[i] >= 3) {
      cout << 0 << endl;
      return 0;
    }
    if (c[i] == 2) {
      a.push_back(i);
      a.push_back(24 - i);
      use = (use | (1 << i));
    }
  }

  int ans = 0;
  REP(i, (1 << 12)) {
    vi b;
    REP(j, a.size()) { b.push_back(a[j]); }

    FOR(j, 1, 13) {
      if (c[j] != 1)
        continue;
      if ((i >> (j - 1)) % 2 == 0) {
        b.push_back(j);
      } else {
        b.push_back(24 - j);
      }
    }

    sort(ALL(b));
    int tmp = 50;
    FOR(j, 1, b.size()) { tmp = min(tmp, b[j] - b[j - 1]); }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
