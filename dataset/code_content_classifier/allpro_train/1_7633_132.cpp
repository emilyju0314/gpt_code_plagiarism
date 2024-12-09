#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 100;
const int md = 1000000007;
priority_queue<int, vector<int>, greater<int> > pq;
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
vector<pair<int, int> > hero;
int t, n, arr[mx], m, ans;
bool can(int x, int y) {
  int a = 0, b = hero.size() - 1, mid;
  while (a < b) {
    mid = (a + b) / 2;
    if (hero[mid].first >= x)
      b = mid;
    else
      a = mid + 1;
  }
  return hero[a].first >= x && hero[a].second >= y;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    hero.clear();
    scanf("%d", &n);
    int z = 0;
    for (int i = 0; i < n; i += 1) {
      scanf("%d", &arr[i]);
      z = max(z, arr[i]);
    }
    scanf("%d", &m);
    ans = 0;
    for (int i = 0; i < m; i += 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      hero.push_back(make_pair(x, y));
    }
    sort(hero.begin(), hero.end());
    if (z > hero[hero.size() - 1].first) {
      printf("-1\n");
      continue;
    }
    for (int i = hero.size() - 1 - 1; i >= 0; i -= 1) {
      hero[i].second = max(hero[i + 1].second, hero[i].second);
    }
    int p = 0, monster, cnt;
    while (p < n) {
      bool stop = true;
      monster = 0;
      cnt = 1;
      for (int i = p; i < n; i += 1) {
        monster = max(monster, arr[i]);
        if (can(monster, cnt) == false) break;
        cnt++;
        p++;
      }
      ans++;
    }
    printf("%d\n", ans);
  }
}
