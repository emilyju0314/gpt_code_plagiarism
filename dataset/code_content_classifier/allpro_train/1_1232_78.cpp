#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ")";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 2e3 + 5;
char A[N][N];
char B[N][N];
char C[N];
vector<int> G[4 * N];
vector<int> RG[4 * N];
int vis[4 * N];
int comp[4 * N];
void add_edge(int i, int j) {
  G[i].push_back(j);
  RG[j].push_back(i);
  G[j ^ 1].push_back(i ^ 1);
  RG[i ^ 1].push_back(j ^ 1);
}
stack<int> st;
void dfs(int s) {
  vis[s] = 1;
  for (auto it : G[s]) {
    if (!vis[it]) dfs(it);
  }
  st.push(s);
}
void dfs1(int s, int c) {
  vis[s] = 1;
  comp[s] = c;
  for (auto it : RG[s]) {
    if (!vis[it]) dfs1(it, c);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cin >> A[i][j];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cin >> B[i][j];
  }
  for (int i = 1; i <= n; ++i) cin >> C[i];
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int diff = 1 ^ ((A[i][j] - '0') ^ (B[i][j] - '0'));
      int a = C[i] - '0', b = C[j] - '0';
      if (!diff && !a && !b)
        ok = 0;
      else if (!a && !b)
        continue;
      else if (!b) {
        add_edge((2 * (j + n)) ^ 1 ^ diff, (2 * (j + n)) ^ diff);
      } else if (!a) {
        add_edge((2 * i) ^ 1 ^ diff, (2 * i) ^ diff);
      } else {
        add_edge((2 * i) ^ 1 ^ diff, (2 * (j + n)));
        add_edge((2 * i) ^ diff, (2 * (j + n)) ^ 1);
      }
    }
  }
  if (!ok)
    cout << -1 << "\n";
  else {
    for (int i = 2; i <= 4 * n + 1; ++i) {
      if (!vis[i]) {
        dfs(i);
      }
    }
    memset(vis, 0, sizeof(vis));
    int j = 0;
    while (st.size()) {
      int u = st.top();
      st.pop();
      if (!vis[u]) {
        dfs1(u, ++j);
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (comp[2 * i] == comp[2 * i + 1]) {
        ok = 0;
      } else if (comp[2 * i] > comp[2 * i + 1])
        ++cnt;
      if (comp[2 * (i + n)] == comp[(2 * (i + n)) ^ 1]) {
        ok = 0;
      } else if (comp[2 * (i + n)] > comp[2 * (i + n) + 1])
        ++cnt;
    }
    if (!ok)
      cout << -1 << "\n";
    else {
      cout << cnt << "\n";
      for (int i = 1; i <= n; ++i) {
        if (comp[2 * i] > comp[2 * i + 1]) cout << "row " << i - 1 << "\n";
        if (comp[2 * (i + n)] > comp[2 * (i + n) + 1])
          cout << "col " << i - 1 << "\n";
      }
    }
  }
}
