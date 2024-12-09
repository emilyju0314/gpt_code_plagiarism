#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
int n, mn = 1e9;
long long dis[N];
bool done[N];
vector<pair<int, int>> g[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1, w; j < n; j++) {
      scanf("%d", &w);
      g[i].push_back({j, w});
      g[j].push_back({i, w});
      mn = min(mn, w);
    }
  for (int i = 0; i < n; i++) dis[i] = 1e18;
  for (int i = 0; i < n; i++)
    for (auto &j : g[i]) {
      j.second -= mn;
      dis[i] = min(dis[i], 2LL * j.second);
    }
  for (int k = 0; k < n; k++) {
    long long mn = 1e18;
    int at = 0;
    for (int i = 0; i < n; i++)
      if (!done[i] && dis[i] < mn) {
        mn = dis[i];
        at = i;
      }
    done[at] = 1;
    for (auto i : g[at]) dis[i.first] = min(dis[i.first], dis[at] + i.second);
  }
  for (int i = 0; i < n; i++) printf("%lld\n", dis[i] + (n - 1LL) * mn);
}
