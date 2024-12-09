#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 111;
const int MAXM = 10000;
const int P = 10007;
const int BITLIMIT = 6;
bool islucky(int x) { return x == 4 || x == 7; }
unsigned long long pv[MAXN], qv[MAXN], H[BITLIMIT][MAXN], SegHash[MAXN],
    G[MAXN];
vector<int> v[BITLIMIT];
int F[MAXN];
int f(int x) {
  int r = 0;
  while (x) r += islucky(x % 10), x /= 10;
  return r;
}
inline unsigned long long Hash(unsigned long long H[], int x, int y) {
  return x ? H[y] - H[x - 1] * pv[y - x + 1] : H[y];
}
void init() {
  pv[0] = qv[0] = 1;
  for (int i = 1; i < MAXN; ++i) pv[i] = pv[i - 1] * P;
  qv[1] = pv[MAXM];
  for (int i = 2; i < MAXN; ++i) qv[i] = qv[i - 1] * qv[1];
  for (int i = 0; i < MAXN; ++i) F[i] = f(i);
  for (int buf = 0; buf < BITLIMIT; ++buf) {
    for (int i = 0; i < MAXM; ++i) {
      int d = F[i] + buf;
      H[buf][i] = i ? H[buf][i - 1] * P + d : d;
    }
  }
  for (int i = 0; i < MAXN; ++i) {
    SegHash[i] = i ? SegHash[i - 1] * P + Hash(H[F[i]], 0, MAXM - 1)
                   : Hash(H[F[i]], 0, MAXM - 1);
  }
}
unsigned long long sHash(long long x, long long y) {
  int buf = F[x / MAXM];
  long long lo = x / MAXM * MAXM, hi;
  long long x0 = x / MAXM + 1;
  x0 = x0 * MAXM - 1;
  x0 = min(x0, y);
  unsigned long long r = Hash(H[buf], x - lo, x0 - lo);
  lo = (x / MAXM + 1), hi = y / MAXM - 1;
  if (lo <= hi) r = r * qv[(hi - lo + 1)] + Hash(SegHash, lo, hi);
  lo = (hi + 1) * MAXM;
  hi = y;
  buf = F[lo / MAXM];
  if (lo > x && lo <= hi)
    r = r * pv[hi - lo + 1] + Hash(H[buf], lo - lo, hi - lo);
  return r;
}
void cal(long long A, long long L) {
  G[0] = f(A);
  for (int i = 1; i < MAXM && i < L; ++i) G[i] = G[i - 1] * P + f(A + i);
  for (int buf = 0; buf < BITLIMIT; ++buf) {
    for (int i = 0; i < MAXM; ++i) {
      long long len = min((long long)MAXM - i, L);
      long long lo = 0, hi = len, mid;
      while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (Hash(H[buf], i + 0, i + mid - 1) == Hash(G, 0, mid - 1))
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      hi = lo - 1;
      if (hi == len) v[buf].push_back(i);
    }
  }
}
int main() {
  init();
  long long A, L;
  while (cin >> A >> L) {
    cal(A, L);
    unsigned long long hashval = sHash(A, A + L - 1);
    for (long long i = 0; i < MAXN; ++i) {
      int c = F[i];
      if (v[c].empty()) continue;
      long long offset = i * MAXM;
      for (int j = 0; j < v[c].size(); ++j) {
        int id = v[c][j];
        if (offset + id > A &&
            sHash(offset + id, offset + id + L - 1) == hashval) {
          cout << offset + id << endl;
          goto END;
        }
      }
    }
  END:;
  }
  return 0;
}
