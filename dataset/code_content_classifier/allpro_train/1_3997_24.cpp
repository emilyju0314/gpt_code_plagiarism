#include <bits/stdc++.h>
using std::bitset;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::ios_base;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::nth_element;
using std::pair;
using std::queue;
using std::reverse;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;
struct __Timestamp {
  ~__Timestamp() {}
} __timestamp;
template <typename T>
void debug(T t) {}
template <typename T, typename... Args>
void debug(T t, Args... args) {}
const int N = 105;
const int64_t INF = 2e18;
int n, m;
pair<int, int> p[2 * N];
int64_t k;
int64_t dp[2 * N][2 * N];
void add(int i, int b, int64_t x) {
  if (b >= 0) {
    dp[i][b] += x;
    if (dp[i][b] > INF) dp[i][b] = INF;
  }
}
int64_t get(string& s) {
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  int sz = s.size();
  for (int i = 0; i < sz; ++i) {
    for (int b = 0; b < sz; ++b) {
      if (s[i] == '.') {
        add(i + 1, b + 1, dp[i][b]);
        add(i + 1, b - 1, dp[i][b]);
      } else if (s[i] == '(') {
        add(i + 1, b + 1, dp[i][b]);
      } else {
        add(i + 1, b - 1, dp[i][b]);
      }
    }
  }
  return dp[sz][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  cin >> n >> m >> k;
  for (int i = 0; i < (int)(n + m - 1); i++) {
    p[i].first = 1e9;
    p[i].second = i;
  }
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      int x;
      cin >> x;
      p[i + j].first = std::min(p[i + j].first, x);
    }
  }
  int sz = n + m - 1;
  sort(p, p + sz);
  string s;
  s.resize(sz);
  std::fill(s.begin(), s.end(), '.');
  for (int i = 0; i < sz; ++i) {
    int pos = p[i].second;
    s[pos] = '(';
    int64_t r = get(s);
    if (r < k) {
      k -= r;
      s[pos] = ')';
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      cout << s[i + j];
    }
    cout << '\n';
  }
  return 0;
}
