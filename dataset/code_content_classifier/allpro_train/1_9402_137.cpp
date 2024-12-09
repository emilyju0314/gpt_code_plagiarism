#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const long long INF = 1LL * inf * inf;
const double eps = 1e-9;
const int MAXN = 2500;
const int md = (int)1e9 + 7;
vector<int> vec_ans, way[30000];
vector<pair<int, int> > new_way[30000], new_way_into[30000];
int n, m, dist[4000][4000], new_dist[4000][4000], d[4000], ans;
set<pair<int, int> > q;
inline void dijkstra(pair<int, int> w) {
  q.erase(w);
  int c = w.first, x = w.second;
  for (int i = 0; i < way[x].size(); i++) {
    int to = way[x][i];
    if (d[to] > c + 1) {
      q.erase(make_pair(d[to], to));
      d[to] = c + 1;
      q.insert(make_pair(d[to], to));
    }
  }
}
inline void solve(int x, int y) {
  if (x == y) return;
  int d = 0;
  d = new_dist[x][y];
  if (d == 0) return;
  pair<int, int> mx1 = make_pair(0, -inf), mx2 = make_pair(0, -inf),
                 mxx1 = make_pair(0, -inf), mxx2 = make_pair(0, -inf);
  for (int i = 0; i < min(3, (int)new_way_into[x].size()); i++) {
    if (new_way_into[x][i].first == y) continue;
    if (mx1.first == 0)
      mx1 = new_way_into[x][i];
    else if (mx2.first == 0)
      mx2 = new_way_into[x][i];
  }
  for (int i = 0; i < min(3, (int)new_way[y].size()); i++) {
    if (new_way[y][i].first == x) continue;
    if (mxx1.first == 0)
      mxx1 = new_way[y][i];
    else if (mxx2.first == 0)
      mxx2 = new_way[y][i];
  }
  if (mx1.first != mxx1.first) {
    d += mx1.second + mxx1.second;
    if (d > ans) {
      ans = d;
      vec_ans.clear();
      vec_ans.push_back(mx1.first);
      vec_ans.push_back(x);
      vec_ans.push_back(y);
      vec_ans.push_back(mxx1.first);
    }
  } else {
    if (mx1.second + mxx2.second > mx2.second + mxx1.second) {
      d += mx1.second + mxx2.second;
      if (d > ans) {
        ans = d;
        vec_ans.clear();
        vec_ans.push_back(mx1.first);
        vec_ans.push_back(x);
        vec_ans.push_back(y);
        vec_ans.push_back(mxx2.first);
      }
    } else {
      d += mx2.second + mxx1.second;
      if (d > ans) {
        ans = d;
        vec_ans.clear();
        vec_ans.push_back(mx2.first);
        vec_ans.push_back(x);
        vec_ans.push_back(y);
        vec_ans.push_back(mxx1.first);
      }
    }
  }
}
bool cmp(pair<int, int> x, pair<int, int> y) { return y.second < x.second; }
int main() {
  ios_base ::sync_with_stdio(0);
  ;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    way[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) d[j] = inf;
    d[i] = 0;
    q.insert(make_pair(d[i], i));
    while (!q.empty()) {
      dijkstra(*(q.begin()));
    }
    for (int j = 1; j <= n; j++) {
      if (d[j] != inf && i != j)
        new_way[i].push_back(make_pair(j, d[j])),
            new_way_into[j].push_back(make_pair(i, d[j])),
            new_dist[i][j] = d[j];
    }
  }
  for (int i = 1; i <= n; i++)
    sort((new_way[i]).begin(), (new_way[i]).end(), cmp),
        sort((new_way_into[i]).begin(), (new_way_into[i]).end(), cmp);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) solve(i, j);
  for (int i = 0; i < vec_ans.size(); i++) cout << vec_ans[i] << " ";
  return 0;
}
