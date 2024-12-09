#include <bits/stdc++.h>
long long ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long dx[4] = {-1, 1, 0, 0};
long long dy[4] = {0, 0, -1, 1};
using namespace std;
const long long MOD = 1000000007, M = 200100;
string s, v;
pair<long long, long long> p[M];
pair<char, char> t[M];
vector<long long> am[M];
vector<long long> am2[M];
long long srt[M];
long long num, n, m;
bool vis[M];
long long clr[M];
void dfs(long long v) {
  vis[v] = 1;
  for (long long i(0); i != am[v].size(); i += (0 <= am[v].size() ? 1 : -1))
    if (!vis[am[v][i]]) dfs(am[v][i]);
  srt[num++] = v;
}
void cmp(long long v, long long id) {
  clr[v] = id;
  for (long long i(0); i != am2[v].size(); i += (0 <= am2[v].size() ? 1 : -1))
    if (clr[am2[v][i]] == -1) cmp(am2[v][i], id);
}
bool SAT(string t) {
  for (long long i(0); i != n; i += (0 <= n ? 1 : -1))
    if (t[i] != '#') {
      if (v[t[i] - 'a'] == 'C')
        am[i].push_back(i + n), am2[i + n].push_back(i);
      else
        am[i + n].push_back(i), am2[i].push_back(i + n);
    }
  num = 0;
  for (long long i(0); i != n << 1; i += (0 <= n << 1 ? 1 : -1))
    vis[i] = 0, clr[i] = -1;
  for (long long i(0); i != n << 1; i += (0 <= n << 1 ? 1 : -1))
    if (!vis[i]) dfs(i);
  reverse(srt, srt + num);
  long long id = 0;
  for (long long i(0); i != n << 1; i += (0 <= n << 1 ? 1 : -1))
    if (clr[srt[i]] == -1) cmp(srt[i], ++id);
  for (long long i(0); i != n; i += (0 <= n ? 1 : -1))
    if (t[i] != '#') {
      if (v[t[i] - 'a'] == 'C')
        am[i].pop_back(), am2[i + n].pop_back();
      else
        am[i + n].pop_back(), am2[i].pop_back();
    }
  for (long long i(0); i != n; i += (0 <= n ? 1 : -1))
    if (clr[i] == clr[i + n]) return 0;
  return 1;
}
int main() {
  long long C, V;
  C = V = 0;
  cin >> v;
  for (long long i(0); i != v.size(); i += (0 <= v.size() ? 1 : -1))
    (v[i] == 'V' ? V : C)++;
  cin >> n >> m;
  for (long long i(0); i != m; i += (0 <= m ? 1 : -1)) {
    cin >> p[i].first >> t[i].first;
    cin >> p[i].second >> t[i].second;
    p[i].first--;
    p[i].second--;
    if (t[i].first == 'C') p[i].first += n;
    if (t[i].second == 'C') p[i].second += n;
    am[p[i].first].push_back(p[i].second);
    am2[p[i].second].push_back(p[i].first);
    if (p[i].first < n)
      p[i].first += n;
    else
      p[i].first -= n;
    if (p[i].second < n)
      p[i].second += n;
    else
      p[i].second -= n;
    am[p[i].second].push_back(p[i].first);
    am2[p[i].first].push_back(p[i].second);
  }
  cin >> s;
  if (SAT(s)) {
    cout << s << endl;
    return 0;
  } else if (!C || !V) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i(n - 1); i != -1; i += (n - 1 <= -1 ? 1 : -1)) {
    pair<long long, long long> f = make_pair(0, 0);
    for (long long j(s[i] + 1 - 'a'); j != v.size();
         j += (s[i] + 1 - 'a' <= v.size() ? 1 : -1)) {
      if (v[j] == 'C') {
        if (f.first) continue;
        f.first++;
      } else {
        if (f.second) continue;
        f.second++;
      }
      string solve = s;
      solve[i] = 'a' + j;
      for (long long k(i + 1); k != n; k += (i + 1 <= n ? 1 : -1))
        solve[k] = '#';
      if (SAT(solve)) {
        for (long long k(i + 1); k != n; k += (i + 1 <= n ? 1 : -1)) {
          pair<long long, long long> g = make_pair(0, 0);
          for (long long l(0); l != v.size(); l += (0 <= v.size() ? 1 : -1)) {
            if (v[l] == 'C') {
              if (g.first) continue;
              g.first++;
            } else {
              if (g.second) continue;
              g.second++;
            }
            solve[k] = 'a' + l;
            if (SAT(solve)) break;
          }
        }
        cout << solve << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
