#include <bits/stdc++.h>
using namespace std;
const long long MXN = 5e5 + 10;
const long long MXS = MXN * 4;
const long long INF = 1e18;
long long n, m, ex;
long long A[MXN], B[MXN], C[MXN], lazy[MXS];
long long mn[MXN], Fen[MXN], ps[MXN];
bool check(long long p = 1) {
  for (int i = 1; i <= n; i++) {
    if (p <= m) p += (A[i] == B[p]);
  }
  return (p > m);
}
void Upd(long long p, long long x) {
  for (; p < MXN; p += p & -p) Fen[p] += x;
}
long long Get(long long p) {
  long long s = 0;
  for (; p; p -= p & -p) s += Fen[p];
  return s;
}
long long Get(long long l, long long r) {
  if (r < l) return 0;
  return Get(r) - Get(l - 1);
}
void Shift(long long id, long long s, long long e) {
  if (!lazy[id]) return;
  if ((e - s + 1) > 1) {
    lazy[(id * 2)] += lazy[id];
    lazy[(id * 2 + 1)] += lazy[id];
  } else
    mn[s] += lazy[id];
  lazy[id] = 0;
}
void Push(long long p, long long id = 1, long long s = 1,
          long long e = MXN - 1) {
  Shift(id, s, e);
  if ((e - s + 1) == 1) return;
  if (p <= ((s + e) / 2))
    Push(p, (id * 2), s, ((s + e) / 2));
  else
    Push(p, (id * 2 + 1), ((s + e) / 2 + 1), e);
}
void Add(long long l, long long r, long long x, long long id = 1,
         long long s = 1, long long e = MXN - 1) {
  if (e < l || s > r || r < l) return;
  if (l <= s && e <= r) {
    lazy[id] += x;
    Shift(id, s, e);
    return;
  }
  Add(l, r, x, (id * 2), s, ((s + e) / 2)),
      Add(l, r, x, (id * 2 + 1), ((s + e) / 2 + 1), e);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n, fill(mn, mn + MXN, INF);
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> C[i];
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> B[i];
  if (!check()) return cout << "NO\n", 0;
  cout << "YES\n";
  for (int i = n; i; i--) ps[i] = ps[i + 1] + (A[i] > B[m] ? C[i] : 0);
  mn[0] = 0;
  B[m + 1] = MXN - 1;
  for (int i = 1; i <= n; i++) {
    if (A[i] > B[m]) {
      ex += C[i];
      continue;
    }
    long long ind = lower_bound(B + 1, B + m + 1, A[i]) - B;
    if (B[ind] != A[i]) {
      if (C[i] > 0)
        Upd(A[i], C[i]);
      else
        ex += C[i];
      continue;
    }
    long long cost = Get(B[ind - 1] + 1, B[ind]);
    Push(B[ind]);
    if (C[i] < 0) mn[B[ind]] += C[i];
    mn[B[ind]] = min(mn[B[ind]], cost + mn[B[ind - 1]]);
    if (C[i] < 0)
      ex += C[i], Add(A[i], A[i], -C[i]);
    else
      Upd(A[i], C[i]);
  }
  cout << mn[B[m]] + ex << '\n';
  return 0;
}
