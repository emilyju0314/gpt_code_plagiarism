#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9 + 17;
void self_max(ll &a, ll b) { a = max(a, b); }
void self_min(ll &a, ll b) { a = min(a, b); }
int n, m, d, s;
queue<int> Q;
bool ok = true;
int v[1001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> d;
  for (int x, i = 1; i <= m; ++i) {
    cin >> x;
    s += x;
    Q.push(x);
  }
  int ini = 0;
  int nr = 1;
  for (int i = 1; i <= n && ok; ++i) {
    if (ini + d == i && s < n - i + 1) {
      if (!Q.empty()) {
        int ceva = Q.front();
        s -= ceva;
        for (int j = i; j <= i + ceva - 1; ++j) v[j] = nr;
        ini = i + ceva - 1;
        i = i + ceva - 2;
        Q.pop();
        nr++;
      } else
        ok = false;
    } else {
      if (s == n - i + 1) {
        int unde = i;
        while (!Q.empty()) {
          int ceva = Q.front();
          Q.pop();
          for (int j = unde; j <= unde + ceva - 1; ++j) v[j] = nr;
          unde += ceva;
          nr++;
        }
        i = n;
      }
    }
  }
  if (ok) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << v[i] << ' ';
  } else
    cout << "NO";
}
