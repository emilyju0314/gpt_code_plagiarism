#include <bits/stdc++.h>
using namespace std;
const int maxN = 250000 + 10;
bool mark[maxN];
int n, sz;
int x[maxN], y[maxN], m[maxN], p[maxN], r[maxN];
long long dis[maxN];
queue<int> qu;
vector<long long> Q;
vector<int> cost[1 << 20];
long long getD(long long x, long long y, long long xx, long long yy) {
  return (x - xx) * (x - xx) + (y - yy) * (y - yy);
}
int getId(long long x) {
  return upper_bound(Q.begin(), Q.end(), x) - Q.begin() - 1;
}
bool cmp(const int &a, const int &b) { return m[a] < m[b]; }
void build(int root, int lo, int hi) {
  if (lo == hi) {
    reverse(cost[root].begin(), cost[root].end());
    return;
  }
  int lef = root * 2;
  int rig = root * 2 + 1;
  int mid = (lo + hi) / 2;
  for (int i = 0; i < (int)cost[root].size(); i++) {
    if (getId(dis[cost[root][i]]) <= mid)
      cost[lef].push_back(cost[root][i]);
    else
      cost[rig].push_back(cost[root][i]);
  }
  build(lef, lo, mid);
  build(rig, mid + 1, hi);
  reverse(cost[root].begin(), cost[root].end());
}
void go(int root, int lo, int hi, int beg, int fin, int val) {
  if (fin < lo || hi < beg) return;
  if (beg <= lo && hi <= fin) {
    while (!cost[root].empty() && m[cost[root].back()] <= val) {
      if (!mark[cost[root].back()]) {
        mark[cost[root].back()] = true;
        qu.push(cost[root].back());
      }
      cost[root].pop_back();
    }
    return;
  }
  int mid = (lo + hi) / 2;
  go((root << 1), lo, mid, beg, fin, val);
  go((root << 1) + 1, mid + 1, hi, beg, fin, val);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x[0] >> y[0] >> p[0] >> r[0] >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> m[i] >> p[i] >> r[i];
    Q.push_back(dis[i] = getD(x[i], y[i], x[0], y[0]));
  }
  sort(Q.begin(), Q.end());
  Q.resize(unique(Q.begin(), Q.end()) - Q.begin());
  sz = (int)Q.size();
  for (int i = 1; i <= n; i++) cost[1].push_back(i);
  sort(cost[1].begin(), cost[1].end(), cmp);
  build(1, 0, sz - 1);
  qu.push(0);
  mark[0] = true;
  int ans = 0;
  while (!qu.empty()) {
    ans++;
    int front = qu.front();
    qu.pop();
    go(1, 0, sz - 1, 0, getId((long long)r[front] * r[front]), p[front]);
  }
  cout << ans - 1 << endl;
  return 0;
}
