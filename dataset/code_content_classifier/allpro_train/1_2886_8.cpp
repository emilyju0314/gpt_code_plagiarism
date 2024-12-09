#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long INF = 1e18 + 7;
long long h, a[N], d[N];
int n, m, k, c[N], add[N];
bool vis[N], vd[N];
priority_queue<pair<int, int> > que;
vector<long long> step;
void bfs() {
  for (int i = (0); i < (k); ++i) d[i] = INF, vd[i] = false;
  priority_queue<pair<long long, int> > qd;
  qd.push(make_pair(-1, 1 % k));
  while (!qd.empty()) {
    long long D = -qd.top().first;
    int g = qd.top().second;
    qd.pop();
    if (vd[g]) continue;
    vd[g] = true, d[g] = D;
    for (int i = (0); i < (((int)(step).size())); ++i) {
      int g2 = (D + step[i]) % k;
      if (d[g2] > D + step[i]) {
        d[g2] = D + step[i];
        qd.push(make_pair(-d[g2], g2));
      }
    }
  }
}
void op1(long long x) {
  step.push_back(x);
  bfs();
  for (int i = (1); i < (n + 1); ++i)
    if (!vis[i] && a[i] >= d[a[i] % k]) {
      vis[i] = true;
      que.push(make_pair(c[i], -i));
    }
}
int op3() {
  while (!que.empty()) {
    pair<int, int> p = que.top();
    que.pop();
    if (add[-p.second] == 0) return p.first;
    p.first -= add[-p.second];
    add[-p.second] = 0;
    que.push(p);
  }
  return 0;
}
int main() {
  scanf("%lld%d%d%d", &h, &n, &m, &k);
  for (int i = (1); i < (n + 1); ++i) {
    scanf("%lld%d", &a[i], &c[i]);
    vis[i] = false;
  }
  op1(k);
  for (int _m = (0); _m < (m); ++_m) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      long long x;
      scanf("%lld", &x);
      op1(x);
    } else if (op == 2) {
      int x, y;
      scanf("%d%d", &x, &y);
      add[x] += y;
    } else {
      printf("%d\n", op3());
    }
  }
  return 0;
}
