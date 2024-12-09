#include <bits/stdc++.h>
#pragma GCC optimize "O3"
int n, m;
std::vector<std::vector<std::pair<int, int>>> g;
std::vector<long long> dist;
std::vector<std::vector<long long>> dest;
std::vector<std::vector<std::pair<long long, long long>>> swt;
void dfs1(int v) {
  for (auto& ch : (g[v])) {
    dist[ch.first] = dist[v] + ch.second;
    dfs1(ch.first);
  }
}
std::pair<std::set<long long>, long long> dfs2(int v) {
  std::vector<std::set<long long>> sets;
  std::vector<long long> wei;
  int last = -1;
  std::pair<int, int> big = std::make_pair(-1, -1);
  for (auto& ch : (g[v])) {
    auto pr = dfs2(ch.first);
    if (((int)(pr.first).size()) > 0) {
      sets.push_back(std::move(pr.first));
      wei.push_back(-ch.second + pr.second);
      big = std::max(big, std::make_pair(((int)(sets.back()).size()),
                                         ((int)(sets).size()) - 1));
      last = ((int)(sets).size()) - 1;
    } else
      last = -1;
  }
  long long off = 0;
  if (big.second != -1) {
    std::swap(sets[0], sets[big.second]);
    std::swap(wei[0], wei[big.second]);
    if (last == big.second) last = 0;
    off = wei[0];
    std::set<long long> other;
    for (int i = (1); i < (((int)(sets).size())); ++i)
      for (auto& j : (sets[i]))
        other.insert(j + wei[i] - off), sets[0].insert(j + wei[i] - off);
    for (int i = (1); i < (((int)(sets).size())); ++i)
      for (auto& j : (sets[i])) {
        long long val = j + wei[i] - off;
        auto it = sets[0].lower_bound(val);
        if (it != sets[0].begin() &&
            sets[i].count(*std::prev(it) - wei[i] + off) == 0)
          swt[v].push_back(std::make_pair(*std::prev(it) + off + 1, *it + off));
        if (std::next(it) != sets[0].end() && other.count(*std::next(it)) == 0)
          swt[v].push_back(std::make_pair(*it + off + 1, *std::next(it) + off));
      }
    long long sma = *sets[0].begin();
    if (last == -1)
      swt[v].push_back(std::make_pair(1ll, sma + off));
    else if (last == 0) {
      if (other.count(sma) != 0)
        swt[v].push_back(std::make_pair(1ll, sma + off));
    } else {
      if (sets[last].count(sma - wei[last] + off) == 0)
        swt[v].push_back(std::make_pair(1ll, sma + off));
    }
    std::sort(swt[v].begin(), swt[v].end());
  } else {
    assert(((int)(sets).size()) == 0);
    sets.emplace_back();
  }
  for (auto& i : (dest[v])) sets[0].insert(i - off);
  return std::make_pair(std::move(sets[0]), off);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  if (n == 1) {
    std::cout << "-1 0\n";
    return 0;
  }
  g.resize(n);
  dist.resize(n);
  dest.resize(n);
  swt.resize(n);
  for (int i = 0; i < (n - 1); ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back(std::make_pair(b, c));
  }
  dfs1(0);
  for (int i = 0; i < (m); ++i) {
    int s, t;
    std::cin >> s >> t;
    s--;
    dest[s].push_back(t + dist[s]);
  }
  dfs2(0);
  std::vector<std::pair<long long, long long>> prze;
  for (int i = 0; i < (n); ++i) {
    for (auto& j : (swt[i])) prze.push_back(j);
  }
  std::sort(prze.begin(), prze.end());
  std::priority_queue<long long, std::vector<long long>,
                      std::greater<long long>>
      up;
  long long ans = -1;
  auto it = prze.begin();
  long long time = it->first;
  while (it != prze.end() && it->first <= time) {
    assert(it->first == time);
    up.push(it->second);
    it++;
  }
  while (((int)(up).size())) {
    long long cur = up.top();
    up.pop();
    if (cur < time) {
      assert(cur == time - 1);
      ans = cur;
      break;
    }
    time++;
    while (it != prze.end() && it->first <= time) {
      assert(it->first == time);
      up.push(it->second);
      it++;
    }
    if (((int)(up).size()) == 0 && it != prze.end()) {
      time = it->first;
      while (it != prze.end() && it->first <= time) {
        assert(it->first == time);
        up.push(it->second);
        it++;
      }
    }
  }
  if (ans == -1) {
    std::cout << ans << " " << ((int)(prze).size()) << "\n";
  } else {
    std::cout << ans << " ";
    int cnt = 0;
    for (auto& i : (prze))
      if (i.second < ans) cnt++;
    std::cout << cnt << "\n";
  }
  return 0;
}
