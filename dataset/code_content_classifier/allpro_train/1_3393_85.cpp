#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
template <typename T, typename U>
std::istream& operator>>(std::istream& i, pair<T, U>& p) {
  i >> p.x >> p.y;
  return i;
}
template <typename T>
std::istream& operator>>(std::istream& i, vector<T>& t) {
  for (auto& v : t) {
    i >> v;
  }
  return i;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& o, const pair<T, U>& p) {
  o << p.first << ' ' << p.second;
  return o;
}
template <typename T>
std::ostream& operator<<(std::ostream& o, const vector<T>& t) {
  if (t.empty()) o << '\n';
  for (size_t i = 0; i < t.size(); ++i) {
    o << t[i] << " \n"[i == t.size() - 1];
  }
  return o;
}
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}
int n, m;
vector<int> nxt[111111];
vector<pair<int, int>> ans;
int T = 0;
void dfs(int u, int p = -1) {
  int x = T;
  ans.push_back({u + 1, T});
  int lo = max(0, T - (int)nxt[u].size());
  int hi = lo + nxt[u].size();
  for (int v : nxt[u]) {
    if (v == p) continue;
    if (T >= hi) {
      T = lo;
      ans.push_back({u + 1, T});
    }
    T++;
    dfs(v, u);
    T++;
    ans.push_back({u + 1, T});
  }
  if (p != -1 && T != x - 1) {
    ans.push_back({u + 1, x - 1});
    T = x - 1;
  }
}
void solve(istream& cin, ostream& cout) {
  cin >> n;
  for (int(i) = 0; (i) < (int)(n - 1); (i)++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    nxt[u].push_back(v);
    nxt[v].push_back(u);
  }
  dfs(0);
  cout << ans.size() << endl;
  for (int(i) = 0; (i) < (int)(ans.size()); (i)++) cout << ans[i] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve(cin, cout);
  return 0;
}
