#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return string(1, c); }
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(const vector<bool>& v) {
  bool first = true;
  string res = "{";
  for (auto&& i : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(i);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res;
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
bool chmax(T& x, T y) {
  return x < y and (x = y, true);
}
template <typename T>
bool chmin(T& x, T y) {
  return x > y and (x = y, true);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    int yat;
    cin >> yat;
    --yat;
    int xat = 0;
    while (xat < n) {
      if (grid[xat][yat] == 1) {
        grid[xat][yat] = 2;
        ++yat;
      } else if (grid[xat][yat] == 3) {
        grid[xat][yat] = 2;
        --yat;
      } else {
        ++xat;
      }
    }
    cout << yat + 1 << ' ';
  }
  return 0;
}
