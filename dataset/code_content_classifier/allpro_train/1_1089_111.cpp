#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
int p[N], a[N], n, m, q[N], nxt[N], lst[N];
set<pair<int, int> > st;
bool cmp(int a, int b) { return p[a] < p[b]; };
int cal(int x, int y) {
  if (x == y) return INF;
  int d = (p[y] - p[x] + m) % m;
  if (y < x) d = (d + a[y]) % m;
  if (d <= a[x]) return 1;
  if (a[x] <= a[y]) return INF;
  return (d - a[y] - 1) / (a[x] - a[y]) + 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i] >> a[i], p[i]--, q[i] = i;
  sort(&q[1], &q[n + 1], cmp);
  for (int i = 1; i <= n; i++) nxt[q[i]] = q[i + 1], lst[q[i]] = q[i - 1];
  nxt[q[n]] = q[1];
  lst[q[1]] = q[n];
  for (int i = 1; i <= n; i++) st.insert({cal(i, nxt[i]), i});
  while (1) {
    pair<int, int> u = *st.begin();
    if (u.first == INF) break;
    int v = u.second;
    st.erase(st.begin());
    st.erase(make_pair(cal(nxt[v], nxt[nxt[v]]), nxt[v]));
    if (!st.empty()) st.erase(make_pair(cal(lst[v], v), lst[v]));
    p[v] += u.first;
    p[v] %= m;
    --a[v];
    nxt[v] = nxt[nxt[v]];
    lst[nxt[v]] = v;
    st.insert(make_pair(cal(lst[v], v), lst[v]));
    st.insert(make_pair(cal(v, nxt[v]), v));
  }
  cout << st.size() << endl;
  for (set<pair<int, int> >::iterator it = st.begin(); it != st.end(); it++)
    printf("%d ", it->second);
  return 0;
}
