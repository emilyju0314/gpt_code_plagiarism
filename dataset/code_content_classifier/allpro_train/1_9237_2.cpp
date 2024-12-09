#include <bits/stdc++.h>
using namespace std;
struct node {
  int nxt;
  long long sta, v[10];
  node() {
    nxt = 0;
    memset(v, 0, sizeof(v));
  }
};
struct state {
  vector<node> nodes;
  int head[100007];
  state() { memset(head, -1, sizeof(head)); }
  size_t size() const { return nodes.size(); }
  void sum() {
    for (int i = 0; i < nodes.size(); i++)
      for (int j = 1; j <= 9; j++) nodes[i].v[j] += nodes[i].v[j - 1];
  }
  void update(int at, long long key, long long v) {
    int tmp = key % 100007;
    for (int i = head[tmp]; i != -1; i = nodes[i].nxt)
      if (nodes[i].sta == key) {
        nodes[i].v[at] += v;
        return;
      }
    node now;
    now.nxt = head[tmp];
    head[tmp] = nodes.size();
    now.v[at] += v;
    now.sta = key;
    nodes.push_back(now);
  }
  long long find(int at, long long key) {
    int tmp = key % 100007;
    for (int i = head[tmp]; i != -1; i = nodes[i].nxt)
      if (nodes[i].sta == key) return nodes[i].v[at];
    return 0;
  }
} f[11][20];
long long c[2][20], bit[15];
bitset<90> vis[15], pre[90], tmp;
void dfs(int dep, int cnt, int sum, long long msk) {
  int mx = sum + (18 - cnt) * 9;
  tmp = pre[mx >> 1];
  if (sum >> 1) tmp ^= pre[(sum >> 1) - 1];
  if ((vis[dep - 1] & tmp) == tmp) return;
  if (dep == 10) {
    for (int i = sum >> 1; i >= 0; i--)
      if (vis[dep - 1][i]) {
        int dif = sum - i - i;
        if (dif > 1) f[dif][0].update(0, msk, 1);
        break;
      }
    return;
  }
  vis[dep] = vis[dep - 1];
  dfs(dep + 1, cnt, sum, msk);
  for (; cnt < 18;) {
    vis[dep] |= vis[dep] << dep;
    dfs(dep + 1, ++cnt, sum += dep, msk += bit[dep]);
  }
}
long long solve(int dif, long long lim) {
  char dig[22];
  int len = 0;
  for (; lim; dig[len++] = lim % 10, lim /= 10)
    ;
  reverse(dig, dig + len);
  long long ans = 0, msk = 0;
  state *F = f[dif];
  for (int i = 0; i < len; i++)
    if (len - i > 18) {
      for (int j = 0; j < dig[i]; j++) ans += F[len - i - 1].find(9, msk);
    } else if (dig[i]) {
      ans += F[len - i].find(dig[i] - 1, msk);
      msk += bit[dig[i]];
    }
  return ans;
}
long long solve2(long long lim) {
  char dig[22];
  int len = 0;
  for (; lim; dig[len++] = lim % 10, lim /= 10)
    ;
  reverse(dig, dig + len);
  long long ans = 0;
  int part = 0;
  for (int i = 0; i < len; i++) {
    int odd = dig[i] >> 1, even = dig[i] - odd;
    ans += c[part][len - 1 - i] * odd + c[part ^ 1][len - 1 - i] * even;
    part ^= dig[i] & 1;
  }
  return ans;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 - 48 + ch;
  return x;
}
int main() {
  pre[0][0] = 1;
  for (int i = 1; i <= 85; i++) pre[i] = pre[i - 1], pre[i][i] = 1;
  c[0][0] = 1;
  for (int i = 1; i <= 18; i++)
    c[0][i] = c[1][i] = 5 * (c[0][i - 1] + c[1][i - 1]);
  bit[1] = 1;
  for (int i = 2; i < 10; i++) bit[i] = bit[i - 1] << 5;
  vis[0].set(0);
  dfs(1, 0, 0, 0);
  for (int i = 2; i < 10; i++) {
    f[i][0].sum();
    for (int j = 0; j < 18; j++) {
      state &cur = f[i][j], &nxt = f[i][j + 1];
      for (int id = 0, sz = cur.size(); id < sz; id++) {
        int cnt = j;
        long long way = cur.nodes[id].v[9];
        long long msk = cur.nodes[id].sta, tmp = msk;
        for (int k = 1; k < 10; k++, tmp >>= 5) {
          int rem = tmp & 31;
          if (!rem) continue;
          cnt += rem;
          nxt.update(k, msk - bit[k], way);
        }
        if (cnt < 18) nxt.update(0, msk, way);
      }
      nxt.sum();
    }
  }
  int Q = read();
  long long values = 3287462318;
  while (Q--) {
    long long L = read(), R = read();
    int k = read();
    long long ans = R - L + 1;
    if (!k) {
      ans -= solve2(R + 1) - solve2(L);
      for (int i = 2; i < 10; i += 2) ans -= solve(i, R + 1) - solve(i, L);
    } else
      for (int i = k + 1; i < 10; i++) ans -= solve(i, R + 1) - solve(i, L);
    printf("%lld\n", ans);
  }
}
