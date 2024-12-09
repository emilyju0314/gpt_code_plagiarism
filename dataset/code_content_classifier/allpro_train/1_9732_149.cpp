#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int inf = 1000000010;
const long long INF = 1000000000000000010ll;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 20;
long long ans, k, inv;
int n, m, x, y, u, v, a, b;
int A[MAXN];
vector<int> comp;
struct FENWICK {
  int fen[MAXN];
  void add(int pos, int val) {
    fen[0] += val;
    for (; pos < MAXN; pos += pos & -pos) fen[pos] += val;
  }
  int get(int pos) {
    int res = 0;
    for (; pos; pos -= pos & -pos) res += fen[pos];
    return res;
  }
} fen1, fen2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    comp.push_back(A[i]);
  }
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  for (int i = 1; i <= n; i++) {
    A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
    inv += fen1.fen[0] - fen1.get(A[i]);
    fen1.add(A[i], +1);
  }
  if (inv <= k) return cout << n * (n - 1ll) / 2 << "\n", 0;
  ;
  int r = n;
  for (int l = n; l > 1; l--) {
    fen1.add(A[l], -1);
    inv -= fen1.fen[0] - fen1.get(A[l]);
    inv -= fen2.get(A[l] - 1);
    while (l < r) {
      inv += fen2.get(A[r] - 1);
      inv += fen1.fen[0] - fen1.get(A[r]);
      if (inv > k) {
        inv -= fen2.get(A[r] - 1);
        inv -= fen1.fen[0] - fen1.get(A[r]);
        break;
      }
      fen2.add(A[r--], +1);
    }
    ans += n - r;
  }
  cout << ans << "\n";
  return 0;
}
