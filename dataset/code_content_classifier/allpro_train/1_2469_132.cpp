#include <bits/stdc++.h>
using namespace std;
const long long nmax = 500005;
long long n, m, i, j, cnt, mlc, r, c, R[nmax], S[nmax], solR[nmax], solS[nmax],
    solA, solB, minr, mins;
long long tsort[nmax], where[nmax];
string s[nmax], t, u;
unordered_map<string, int> was;
vector<int> v[nmax], g[nmax], comp[nmax], V[nmax];
bitset<nmax> viz;
void dfs(long long x) {
  viz[x] = 1;
  for (auto it : v[x])
    if (!viz[it]) dfs(it);
  tsort[++c] = x;
}
void dfst(long long x) {
  comp[c].push_back(x);
  where[x] = c;
  viz[x] = 1;
  for (auto it : g[x])
    if (!viz[it]) dfst(it);
}
void dfsc(long long x) {
  viz[x] = 1;
  for (auto it : V[x])
    if (!viz[it]) dfsc(it);
  tsort[++cnt] = x;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
    mlc = s[i].size();
    r = 0;
    for (j = 0; j < mlc; j++) {
      if (s[i][j] >= 'A' && s[i][j] <= 'Z') s[i][j] += 32;
      if (s[i][j] == 'r') r++;
    }
    if (!was[s[i]]) {
      was[s[i]] = ++cnt;
      R[cnt] = r;
      S[cnt] = mlc;
    }
  }
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> t >> u;
    mlc = t.size();
    r = 0;
    for (j = 0; j < mlc; j++) {
      if (t[j] >= 'A' && t[j] <= 'Z') t[j] += 32;
      if (t[j] == 'r') r++;
    }
    if (!was[t]) {
      was[t] = ++cnt;
      R[cnt] = r;
      S[cnt] = mlc;
    }
    mlc = u.size();
    r = 0;
    for (j = 0; j < mlc; j++) {
      if (u[j] >= 'A' && u[j] <= 'Z') u[j] += 32;
      if (u[j] == 'r') r++;
    }
    if (!was[u]) {
      was[u] = ++cnt;
      R[cnt] = r;
      S[cnt] = mlc;
    }
    v[was[t]].push_back(was[u]);
    g[was[u]].push_back(was[t]);
  }
  c = 0;
  for (i = 1; i <= cnt; i++)
    if (!viz[i]) dfs(i);
  viz = 0;
  c = 0;
  for (i = cnt; i; i--)
    if (!viz[tsort[i]]) {
      c++;
      dfst(tsort[i]);
    }
  for (i = 1; i <= c; i++) {
    solR[i] = solS[i] = 1LL << 60;
    for (auto it : comp[i]) {
      if (R[it] < solR[i]) {
        solR[i] = R[it];
        solS[i] = S[it];
      } else if (R[it] == solR[i]) {
        if (S[it] < solS[i]) {
          solR[i] = R[it];
          solS[i] = S[it];
        }
      }
    }
  }
  for (i = 1; i <= cnt; i++)
    for (auto it : v[i]) V[where[i]].push_back(where[it]);
  viz = 0;
  cnt = 0;
  for (i = 1; i <= c; i++)
    if (!viz[i]) dfsc(i);
  for (i = 1; i <= c; i++)
    for (auto it : V[tsort[i]]) {
      if (solR[it] < solR[tsort[i]]) {
        solR[tsort[i]] = solR[it];
        solS[tsort[i]] = solS[it];
      } else if (solR[it] == solR[tsort[i]]) {
        if (solS[it] < solS[tsort[i]]) {
          solR[tsort[i]] = solR[it];
          solS[tsort[i]] = solS[it];
        }
      }
    }
  for (i = 1; i <= n; i++) {
    solA += solR[where[was[s[i]]]];
    solB += solS[where[was[s[i]]]];
  }
  cout << solA << " " << solB;
  return 0;
}
