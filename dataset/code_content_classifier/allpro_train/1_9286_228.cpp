#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;
void ECHO(string _s) { cout << _s; }
void ECHO(bool _s) {
  if (_s)
    cout << "true";
  else
    cout << "false";
}
void ECHO(char _s) { cout << _s; }
void ECHO(long unsigned _s) { cout << _s; }
void ECHO(int _s) { cout << _s; }
void ECHO(long long _s) {
  if (_s == inf)
    cout << "inf";
  else
    cout << _s;
}
void ECHO(double _s) { cout << _s; }
void ECHO(long double _s) { cout << _s; }
void ECHO(bitset<8> b) { cout << b; }
template <typename T>
void ECHO(set<T> _s) {
  for (auto el : _s) {
    ECHO(el);
    cout << "_";
  }
}
template <typename T1, typename T2>
void ECHO(map<T1, T2> _s) {
  for (auto el : _s) {
    ECHO(el);
    cout << "_";
  }
}
template <typename T1, typename T2>
void ECHO(pair<T1, T2> _s) {
  cout << "(";
  ECHO(_s.first);
  cout << ",";
  ECHO(_s.second);
  cout << ")";
}
template <typename T>
void ECHO(vector<T> v) {
  for (auto el : v) {
    ECHO(el);
    cout << "_";
  }
}
template <typename T, typename... Args>
void ECHO(string _s, T x, Args... args) {
  int _i, c = 0;
  for (_i = 0; _i < (int)_s.size(); _i++) {
    if (c == 0 && _s[_i] == ',') break;
    if (_s[_i] == '(') c++;
    if (_s[_i] == ')') c--;
  }
  cout << " (" << _s.substr(0, _i) << "): ";
  ECHO(x);
  while (_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) _i++;
  ECHO(_s.substr(_i), args...);
}
const int MAX = 25;
class DSU {
  vector<int> parent;
  vector<int> rank;

 public:
  DSU() : parent(MAX, 0), rank(MAX, 0) {
    for (int i = 0; i < MAX; ++i) parent[i] = i;
  }
  int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
  }
  bool connected(int a, int b) { return find_parent(a) == find_parent(b); }
  void Union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return;
    if (rank[a] > rank[b])
      parent[b] = a;
    else if (rank[a] < rank[b])
      parent[a] = b;
    else {
      parent[a] = b;
      rank[b]++;
    }
  }
};
int c[22][22];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt, i, j, n, k, ans;
  bool ok;
  string s, t;
  cin >> tt;
  while (tt--) {
    cin >> n;
    cin >> s;
    cin >> t;
    for (i = 0; i < 22; i++) {
      for (j = 0; j < 22; j++) {
        c[i][j] = 0;
      }
    }
    ok = true;
    ans = 0;
    DSU dsu;
    for (i = 0; i < n; i++) {
      if (s[i] - 'a' > t[i] - 'a') ok = false;
      if (s[i] - 'a' >= t[i] - 'a') continue;
      c[s[i] - 'a'][t[i] - 'a'] = 1;
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    for (i = 22 - 1; i >= 0; i--) {
      for (j = 0; j < 22; j++) {
        if (c[i][j] > 0) {
          if (!dsu.connected(i, j)) {
            dsu.Union(i, j);
            ans++;
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
