#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
int SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
int SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, int x1 = 0, int x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) {
  string t = "";
  for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords) {
  int rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cerr << to_string(H) << " | ";
  dbgm(T...);
}
bool vectorpair_sort_by_sec(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
bool custom_compare(const pair<int, int> &p1, const pair<int, int> &p2) {
  if (p1.second < p2.second)
    return true;
  else
    return false;
}
long long _pow(long long a, long long b) {
  long long ans = 1;
  for (int i = 1; i <= b; i++) {
    ans = (ans * a) % 998244353;
  }
  return ans;
}
void prep() {}
void testcase() {
  long long n;
  cin >> n;
  long long m = 0, u = 0;
  while (1) {
    bool ok = false;
    for (long long i = 1; i < n; i++) {
      long long k = n * i;
      long long a = (long long)sqrt(k);
      if (a * a == k) {
        m++;
        n = sqrt(k);
        if (i != 1) u++;
        ok = true;
      }
      if (ok) break;
    }
    if (ok)
      continue;
    else
      break;
  }
  if (u) m++;
  cout << n << " " << m;
}
int main() {
  time_t t1, t2;
  t1 = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  prep();
  testcase();
}
