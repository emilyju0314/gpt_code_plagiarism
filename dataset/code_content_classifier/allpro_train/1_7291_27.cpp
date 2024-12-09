#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long prime(long long p) {
  if (p == 1) return 0;
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
long long inv(long long a, long long mod) { return powmod(a, mod - 2, mod); }
long long random_modul() {
  uniform_int_distribution<long long> u1(1e9, 2e9);
  long long pepega = u1(rnd);
  while (prime(pepega) != 1) pepega = u1(rnd);
  return pepega;
}
long long get_mex(vector<long long> m) {
  map<long long, long long> find;
  for (long long i = 0; i < m.size(); i++) find[m[i]] = 1;
  for (long long i = 0; i < 300000; i++)
    if (find[i] == 0) return i;
}
vector<vector<pair<long long, long long>>> g;
vector<long long> dist;
vector<pair<pair<long long, long long>, long long>> edges;
vector<long long> ans;
vector<bool> used2;
void dfs(long long v) {
  used2[v] = true;
  if (g[v].size() == 1 && v) {
    ans[v] = 1;
    return;
  }
  for (long long i = 0; i < g[v].size(); i++) {
    if (!used2[g[v][i].first]) {
      used2[g[v][i].first] = true;
      dfs(g[v][i].first);
      ans[v] += ans[g[v][i].first];
    }
  }
  return;
}
void solve() {
  long long a, s;
  cin >> a >> s;
  used2.resize(0);
  used2.resize(a);
  g.resize(0);
  g.resize(a);
  ans.resize(0);
  ans.resize(a);
  edges.resize(0);
  for (long long i = 0; i < a - 1; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    edges.push_back({{x, y}, w});
  }
  dist.resize(0);
  dist.resize(a);
  queue<long long> q;
  vector<bool> used(a);
  q.push(0);
  dist[0] = 0;
  used[0] = true;
  while (!q.empty()) {
    long long c = q.front();
    q.pop();
    for (long long i = 0; i < g[c].size(); i++) {
      pair<long long, long long> kek = g[c][i];
      if (!used[kek.first]) {
        used[kek.first] = true;
        q.push(kek.first);
        dist[kek.first] = dist[c] + 1;
      }
    }
  }
  dfs(0);
  vector<pair<long long, long long>> mem;
  for (long long i = 0; i < edges.size(); i++) {
    long long q1 = edges[i].first.first;
    long long q2 = edges[i].first.second;
    long long w = edges[i].second;
    long long pepega;
    if (dist[q1] > dist[q2])
      pepega = q1;
    else
      pepega = q2;
    long long kek = ans[pepega];
    mem.push_back({kek, w});
  }
  long long sum = 0;
  priority_queue<pair<long long, pair<long long, long long>>> cur;
  for (long long i = 0; i < mem.size(); i++) {
    sum += mem[i].first * mem[i].second;
    cur.push({mem[i].first * (mem[i].second - mem[i].second / 2), mem[i]});
  }
  long long answer = 0;
  while (sum > s) {
    answer++;
    pair<long long, pair<long long, long long>> lol = cur.top();
    cur.pop();
    sum -= lol.first;
    long long new_w = lol.second.second / 2;
    cur.push(
        {lol.second.first * (new_w - new_w / 2), {lol.second.first, new_w}});
  }
  cout << answer << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tututu;
  tututu = 1;
  cin >> tututu;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}
