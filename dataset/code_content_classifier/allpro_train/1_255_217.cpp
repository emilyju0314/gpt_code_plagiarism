#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5, MOD = 1e9 + 7;
struct Nod {
  i64 sum, st, dr;
  int cnt;
};
Nod pom[N * 4];
i64 w[N], pos[N], aib[N];
i64 qval;
int ql, qr, qpos;
int n, q;
static inline int lsb(const int &x) { return x & -x; }
static void aib_update(int pos, i64 val) {
  for (; pos < N; pos += lsb(pos)) aib[pos] += val;
}
static i64 aib_query(int pos) {
  i64 ant = 0;
  for (; pos > 0; pos -= lsb(pos)) ant += aib[pos];
  return ant;
}
static int cbin(int l, int r) {
  i64 targ = (aib_query(r) - aib_query(l - 1) + 1) / 2 + aib_query(l - 1);
  i64 tsum = 0;
  int pos = 0;
  for (int msk = 1 << 20; msk > 0; msk /= 2)
    if (pos + msk < N && tsum + aib[pos + msk] < targ) {
      pos += msk;
      tsum += aib[pos];
    }
  return pos + 1;
}
static void update(int nod, int st, int dr) {
  if (st == dr) {
    pom[nod] = {qval, 0, 0, 1};
    return;
  }
  int mid = (st + dr) / 2;
  if (qpos <= mid)
    update(2 * nod, st, mid);
  else
    update(2 * nod + 1, mid + 1, dr);
  pom[nod].sum = (pom[2 * nod].sum + pom[2 * nod + 1].sum) % MOD;
  pom[nod].cnt = pom[2 * nod].cnt + pom[2 * nod + 1].cnt;
  pom[nod].st = pom[2 * nod].st + pom[2 * nod + 1].st;
  pom[nod].st +=
      (pos[mid + 1] - pos[st] - pom[2 * nod].cnt) * pom[2 * nod + 1].sum;
  pom[nod].dr = pom[2 * nod].dr + pom[2 * nod + 1].dr;
  pom[nod].dr += (pos[dr] - pos[mid] - pom[2 * nod + 1].cnt) * pom[2 * nod].sum;
  pom[nod].st %= MOD, pom[nod].dr %= MOD;
}
static Nod query(int nod, int st, int dr) {
  if (ql <= st && dr <= qr) return pom[nod];
  Nod me, l = {0, 0, 0, 0}, r = {0, 0, 0, 0};
  int mid = (st + dr) / 2, bl = max(ql, st), br = min(qr, dr);
  bool fl = false, fr = false;
  if (ql <= mid) {
    l = query(2 * nod, st, mid);
    fl = true;
  }
  if (mid < qr) {
    r = query(2 * nod + 1, mid + 1, dr);
    fr = true;
  }
  if (fl && !fr) return l;
  if (fr && !fl) return r;
  me.sum = l.sum + r.sum;
  me.cnt = l.cnt + r.cnt;
  me.st = (l.st + r.st) + r.sum * (pos[mid + 1] - pos[bl] - l.cnt);
  me.dr = (l.dr + r.dr) + l.sum * (pos[br] - pos[mid] - r.cnt);
  me.st %= MOD, me.dr %= MOD;
  return me;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  i64 a, b, ant;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> pos[i];
  for (qpos = 1; qpos <= n; ++qpos) {
    cin >> w[qpos];
    qval = w[qpos];
    update(1, 1, n);
    aib_update(qpos, qval);
  }
  while (q--) {
    cin >> a >> b;
    if (a > 0) {
      int p = cbin(a, b);
      ql = a, qr = p;
      ant = query(1, 1, n).dr;
      ql = p, qr = b;
      ant += query(1, 1, n).st;
      cout << (ant % MOD + MOD) % MOD << '\n';
    } else {
      a *= -1;
      qpos = a;
      qval = b;
      aib_update(qpos, qval - w[qpos]);
      w[qpos] = qval;
      update(1, 1, n);
    }
  }
  return 0;
}
