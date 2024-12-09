#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto& x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
map<vector<int>, int> mp;
int sub[111];
void dfs(const vector<vector<int>>& g, int u, int p) {
  sub[u] = 1;
  for (int v : g[u])
    if (v != p) {
      dfs(g, v, u);
      sub[u] += sub[v];
    }
}
pair<int, int> centroid(const vector<vector<int>>& g, int u, int p, int no) {
  for (int v : g[u])
    if (v != p) {
      if (sub[v] > no / 2) return centroid(g, v, u, no);
    }
  int c2 = u;
  for (int v : g[u])
    if (v != p) {
      if (no - sub[v] <= no / 2) c2 = v;
    }
  return {u, c2};
}
int get(const vector<vector<int>>& g, int u, int p) {
  vector<int> yo;
  for (int v : g[u])
    if (v != p) {
      yo.emplace_back(get(g, v, u));
    }
  sort((yo).begin(), (yo).end());
  if (mp.count(yo)) return mp[yo];
  int no = int(mp.size());
  return mp[yo] = no + 1;
}
vector<pair<int, int>> hsh(const vector<vector<int>>& g) {
  int n = int(g.size());
  vector<int> vis(n);
  vector<pair<int, int>> H;
  for (auto i = (0); i <= (n - 1); ++i)
    if (!vis[i]) {
      stack<int> st;
      st.push(i);
      int x = 0, no = 0;
      vis[i] = 1;
      while (!st.empty()) {
        int u = st.top();
        st.pop();
        x += int(g[u].size()), no++;
        for (int v : g[u])
          if (!vis[v]) {
            vis[v] = 1;
            st.push(v);
          }
      }
      if (x != 2 * (no - 1)) {
        return {{-1, -1}};
      }
      dfs(g, i, -1);
      pair<int, int> c = centroid(g, i, -1, sub[i]);
      int h1 = get(g, c.first, c.second);
      int h2 = c.second != c.first ? get(g, c.second, c.first) : -2;
      if (h1 > h2) swap(h1, h2);
      H.emplace_back(h1, h2);
    }
  sort((H).begin(), (H).end());
  return H;
}
int conn(const vector<vector<int>>& g) {
  int n = int(g.size());
  vector<int> vis(n);
  int r = -1;
  for (auto i = (0); i <= (n - 1); ++i)
    if (!g[i].empty()) r = i;
  if (r == -1) return n == 2 ? 0 : -1;
  vis[r] = 1;
  stack<int> st;
  st.push(r);
  int x = 0;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    ++x;
    for (int v : g[u])
      if (!vis[v]) {
        vis[v] = 1;
        st.push(v);
      }
  }
  if (x != n - 1) return -1;
  for (auto i = (0); i <= (n - 1); ++i)
    if (!vis[i]) return i;
  while (1)
    ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    int n, k;
    cin >> n >> k;
    vector<vector<vector<int>>> g(k, vector<vector<int>>(n));
    vector<vector<pair<int, int>>> org;
    bool cant = 0;
    for (auto i = (0); i <= (k - 1); ++i) {
      int x;
      cin >> x;
      for (auto j = (1); j <= (x); ++j) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[i][a].push_back(b), g[i][b].push_back(a);
      }
      org.emplace_back(hsh(g[i]));
      if (org.back()[0].first == -1) {
        cant = 1;
      }
    }
    sort((org).begin(), (org).end());
    bool done = 0;
    if (!cant) {
      for (auto i = (0); i <= (k - 1); ++i) {
        int l = conn(g[i]);
        if (l == -1) continue;
        for (auto j = (0); j <= (n - 1); ++j)
          if (j != l) {
            g[i][l].push_back(j), g[i][j].push_back(l);
            {
              vector<vector<pair<int, int>>> now;
              for (auto u = (0); u <= (n - 1); ++u) {
                vector<int> tmp = g[i][u];
                for (int v : tmp) {
                  g[i][u].erase(find((g[i][u]).begin(), (g[i][u]).end(), v));
                  g[i][v].erase(find((g[i][v]).begin(), (g[i][v]).end(), u));
                }
                now.emplace_back(hsh(g[i]));
                for (int v : tmp) {
                  g[i][u].push_back(v), g[i][v].push_back(u);
                }
              }
              sort((now).begin(), (now).end());
              if (now == org) {
                cout << "YES\n";
                for (auto u = (0); u <= (n - 1); ++u)
                  for (int v : g[i][u])
                    if (u < v) cout << u + 1 << " " << v + 1 << "\n";
                done = 1;
                break;
              }
            }
            g[i][l].erase(find((g[i][l]).begin(), (g[i][l]).end(), j));
            g[i][j].erase(find((g[i][j]).begin(), (g[i][j]).end(), l));
          }
        break;
      }
    }
    if (!done) cout << "NO\n";
  }
  return 0;
}
