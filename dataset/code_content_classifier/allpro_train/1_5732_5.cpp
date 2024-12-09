#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct Node {
  int cnt = 0, sum = 0;
};
Node st[4 * N];
void upd(int i, int d, int l = 0, int r = N - 1, int p = 1) {
  if (i < l || i > r) return;
  st[p].cnt += d;
  st[p].sum += d * i;
  if (l == r) return;
  int mid = (l + r) / 2;
  upd(i, d, l, mid, p * 2);
  upd(i, d, mid + 1, r, p * 2 + 1);
}
int query(int k, int l = 0, int r = N - 1, int p = 1) {
  if (l == r) return k * l;
  int mid = (l + r) / 2;
  if (st[p * 2].cnt >= k) return query(k, l, mid, p * 2);
  return st[p * 2].sum + query(k - st[p * 2].cnt, mid + 1, r, p * 2 + 1);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int> > times[2][2];
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    times[a][b].push_back({t, i + 1});
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      sort(times[i][j].begin(), times[i][j].end());
    }
  }
  if (min(times[0][1].size(), times[1][0].size()) + times[1][1].size() < k) {
    cout << -1;
    return 0;
  }
  int doubleTake = min(k, (int)times[1][1].size());
  int singleTake = k - doubleTake;
  if (singleTake > min(times[0][1].size(), times[1][0].size())) {
    cout << -1;
    return 0;
  }
  if (doubleTake + 2 * singleTake > m) {
    cout << -1;
    return 0;
  }
  int sum = 0;
  for (auto &p : times[0][0]) upd(p.first, 1);
  for (int i = 0; i < times[0][1].size(); i++) {
    if (i < singleTake) {
      sum += times[0][1][i].first;
    } else {
      upd(times[0][1][i].first, 1);
    }
  }
  for (int i = 0; i < times[1][0].size(); i++) {
    if (i < singleTake) {
      sum += times[1][0][i].first;
    } else {
      upd(times[1][0][i].first, 1);
    }
  }
  for (int i = 0; i < times[1][1].size(); i++) {
    if (i < doubleTake) {
      sum += times[1][1][i].first;
    } else {
      upd(times[1][1][i].first, 1);
    }
  }
  int bestSingle = singleTake, bestDouble = doubleTake;
  int ans = sum + query(m - singleTake * 2 - doubleTake);
  while (singleTake <
         min(min(k, (int)times[0][1].size()), (int)times[1][0].size())) {
    sum -= times[1][1][doubleTake - 1].first;
    upd(times[1][1][doubleTake - 1].first, 1);
    sum += times[0][1][singleTake].first;
    upd(times[0][1][singleTake].first, -1);
    sum += times[1][0][singleTake].first;
    upd(times[1][0][singleTake].first, -1);
    doubleTake--;
    singleTake++;
    if (singleTake * 2 + doubleTake > m) break;
    if (ans > sum + query(m - singleTake * 2 - doubleTake)) {
      ans = sum + query(m - singleTake * 2 - doubleTake);
      bestSingle = singleTake;
      bestDouble = doubleTake;
    }
  }
  cout << ans << '\n';
  vector<pair<int, int> > rem;
  for (int i = 0; i < times[0][1].size(); i++) {
    if (i < bestSingle) {
      cout << times[0][1][i].second << ' ';
    } else {
      rem.push_back(times[0][1][i]);
    }
  }
  for (int i = 0; i < times[1][0].size(); i++) {
    if (i < bestSingle) {
      cout << times[1][0][i].second << ' ';
    } else {
      rem.push_back(times[1][0][i]);
    }
  }
  for (int i = 0; i < times[1][1].size(); i++) {
    if (i < bestDouble) {
      cout << times[1][1][i].second << ' ';
    } else {
      rem.push_back(times[1][1][i]);
    }
  }
  for (auto &p : times[0][0]) rem.push_back(p);
  sort(rem.begin(), rem.end());
  int r = m - bestSingle * 2 - bestDouble;
  for (int i = 0; i < r; i++) cout << rem[i].second << ' ';
}
