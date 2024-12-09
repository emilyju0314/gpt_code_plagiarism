#include <bits/stdc++.h>
constexpr int MAXN = 1e6 + 5;
int n, m, k;
int c[MAXN * 2], color[MAXN * 2];
bool r[MAXN * 2];
int cnt, color2[MAXN * 2];
std::vector<int> gr[MAXN * 2];
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> map;
std::vector<int> help[MAXN * 2];
int cl[MAXN * 2];
std::pair<int, int> sort(std::pair<int, int> &j) {
  if (j.first > j.second) {
    std::swap(j.first, j.second);
  }
  return j;
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
    c[i]--;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    if (c[u] != c[v]) {
      std::pair<int, int> j = {c[u], c[v]};
      map[sort(j)].emplace_back(u, v);
    } else {
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
  }
  std::fill(color, color + MAXN, -1);
  for (int i = 0; i < n; i++) {
    std::function<void(int, bool, int)> dfs = [&](int v, bool c,
                                                  int c2) -> void {
      if (color[v] == -1) {
        color[v] = c;
        color2[v] = c2;
        for (int t : gr[v]) {
          dfs(t, !c, c2);
        }
      } else if (color[v] != c) {
        r[::c[v]] = true;
      }
    };
    if (color[i] == -1) {
      dfs(i, false, cnt++);
    }
  }
  {
    int dlt = 0;
    for (int i = 0; i < k; i++) {
      dlt += r[i];
    }
    k -= dlt;
  }
  int64_t ans = ((int64_t(k)) * (k - 1ll)) / 2;
  for (const auto &iter : map) {
    if (r[iter.first.first] || r[iter.first.second]) {
      continue;
    }
    for (const auto &p : iter.second) {
      int u = p.first, v = p.second;
      help[color2[u] * 2].clear();
      help[color2[u] * 2 + 1].clear();
      help[color2[v] * 2].clear();
      help[color2[v] * 2 + 1].clear();
      cl[2 * color2[u]] = -1;
      cl[2 * color2[u] + 1] = -1;
      cl[2 * color2[v]] = -1;
      cl[2 * color2[v] + 1] = -1;
    }
    for (const auto &p : iter.second) {
      int u = p.first, v = p.second;
      help[color2[u] * 2 + color[u]].push_back(color2[v] * 2 + color[v]);
      help[color2[v] * 2 + color[v]].push_back(color2[u] * 2 + color[u]);
      help[color2[u] * 2 + 1].push_back(color2[u] * 2);
      help[color2[u] * 2].push_back(color2[u] * 2 + 1);
      help[color2[v] * 2 + 1].push_back(color2[v] * 2);
      help[color2[v] * 2].push_back(color2[v] * 2 + 1);
    }
    bool gg = false;
    std::function<void(int, bool)> dfs = [&](int v, bool c) -> void {
      if (cl[v] == -1) {
        cl[v] = c;
        for (int t : help[v]) {
          dfs(t, !c);
        }
      } else if (cl[v] != c) {
        gg = true;
      }
    };
    for (const auto &p : iter.second) {
      int u = p.first, v = p.second;
      u = color2[u] * 2;
      v = color2[v] * 2;
      if (cl[u] == -1) {
        dfs(u, false);
      }
      if (cl[v] == -1) {
        dfs(v, false);
      }
    }
    ans -= gg;
  }
  std::cout << ans << '\n';
  std::cout.flush();
  return 0;
}
