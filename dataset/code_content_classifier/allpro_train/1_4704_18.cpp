#include <bits/stdc++.h>
using namespace std;
struct entry {
  int v;
  int d;
  entry(int _v, int _d) {
    v = _v;
    d = _d;
  }
  bool operator<(const entry &other) const { return d > other.d; }
};
priority_queue<entry> pq;
char vol[100010];
vector<int> al[100010];
int dist[100010];
int main() {
  int n, m, k, s, t, r, i, j, newd, con = 0, ans = 0;
  entry cur(0, 0);
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < k; i++) {
    scanf("%d", &r);
    vol[r] = 1;
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &s, &t);
    al[s].push_back(t);
    al[t].push_back(s);
  }
  scanf("%d %d", &s, &t);
  pq.push(entry(s, 0));
  for (i = 1; i <= n; i++) dist[i] = 99999999;
  while (!pq.empty()) {
    cur = pq.top();
    pq.pop();
    ans = max(ans, cur.d);
    if (cur.v == t) {
      con = 1;
      break;
    }
    if (cur.d < dist[cur.v]) {
      dist[cur.v] = cur.d;
      if (vol[cur.v])
        newd = 1;
      else
        newd = cur.d + 1;
      for (i = 0; i < al[cur.v].size(); i++) {
        if (newd < dist[al[cur.v][i]]) pq.push(entry(al[cur.v][i], newd));
      }
    }
  }
  printf("%d\n", con ? ans : -1);
  return 0;
}
