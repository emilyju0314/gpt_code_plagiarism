#include <bits/stdc++.h>
#pragma GCC target("sse2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize "trapv"
using namespace std;
const int maxn = 1000500;
inline int g() {
  int x;
  cin >> x;
  return x;
}
inline long long gl() {
  long long x;
  cin >> x;
  return x;
}
inline char gc() {
  char x;
  cin >> x;
  return x;
}
inline string gs() {
  string s;
  cin >> s;
  return s;
}
template <typename T>
inline vector<T> gv(int len) {
  vector<T> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<int> gv(int len) {
  vector<int> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<pair<int, int>> gv_andPairCnt(int len) {
  vector<pair<int, int>> a(len);
  int i = 1;
  for (auto &it : a) {
    it.second = i;
    i++;
    cin >> it.first;
  }
  return a;
}
double power_log(double power, double val) { return log(val) / log(power); }
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it : v) os << it << ", ";
  os << "\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  os << "deque:{";
  for (auto it : v) os << it << " ";
  os << "}\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "set:{";
  for (auto it : v) os << it << " ";
  os << "}";
  return os;
}
template <typename T, typename T2>
ostream &operator<<(ostream &os, const map<T, T2> &v) {
  os << "map:{\n";
  for (auto it : v) os << "    {" << it.first << " <> " << it.second << "}\n";
  os << "}\n";
  return os;
}
template <typename T, typename T2>
ostream &operator<<(ostream &os, const pair<T, T2> &v) {
  os << "{" << v.first << ", " << v.second << "}";
  return os;
}
template <typename T, typename H>
inline vector<pair<T, H>> gv_andBiPair(int len) {
  vector<pair<T, H>> a(len);
  for (auto &it : a) {
    cin >> it.first >> it.second;
  }
  return a;
}
template <typename T>
inline set<T> vector_to_set(const vector<T> &vec) {
  set<T> s;
  for (auto &it : vec) s.insert(it);
  return s;
}
const long long md = 1e9 + 7;
long long dp[maxn][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = g();
  using pii = pair<int, int>;
  map<int, vector<pii>> mp;
  for (int i = 1; i <= n; i++) {
    int l = g(), r = g();
    mp[max(l, r)].emplace_back(l, r);
  }
  vector<vector<pii>> tmp;
  tmp.push_back({{0, 0}, {0, 0}});
  vector<long long> sum = {0};
  auto dist = [](pii l, pii r) {
    return abs(l.first - r.first) + abs(l.second - r.second);
  };
  auto cmp = [](pii l, pii r) {
    return (l.first - l.second) < (r.first - r.second);
  };
  for (auto &it1 : mp) {
    sort(it1.second.begin(), it1.second.end(), cmp);
    long long t1 = 0;
    for (int i = 1; i < it1.second.size(); i++) {
      t1 += dist(it1.second[i - 1], it1.second[i]);
    }
    sum.emplace_back(t1);
    vector<pii> t2 = {it1.second[0], it1.second.back()};
    tmp.push_back(t2);
  }
  for (int i = 1; i < tmp.size(); i++) {
    for (int j = 0; j < (2); ++j) {
      dp[i][j] = 1e18;
    }
    for (int j = 0; j < (2); ++j) {
      for (int k = 0; k < (2); ++k) {
        dp[i][1 - j] =
            min(dp[i][1 - j],
                0ll + dp[i - 1][k] + dist(tmp[i][j], tmp[i - 1][k]) + sum[i]);
      }
    }
    if (tmp[i][0] == tmp[i][1]) {
      assert(dp[i][0] == dp[i][1]);
    }
  }
  cout << min(dp[tmp.size() - 1][0], dp[tmp.size() - 1][1]);
}
