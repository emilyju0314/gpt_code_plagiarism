#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
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
long long n, k, cost;
pair<int, int> sa, sb;
void solve() {
  cost = 0;
  cin >> n >> k >> sa.first >> sa.second >> sb.first >> sb.second;
  long long maxprofit, i, diff;
  cost = LLONG_MAX;
  if (max(sa.first, sb.first) <= min(sa.second, sb.second)) {
    long long rem =
        max(0LL, k - n * (min(sa.second, sb.second) - max(sa.first, sb.first)));
    maxprofit = (abs(sa.first - sb.first) + abs(sa.second - sb.second)) * n;
    cost = min(rem, maxprofit) + max(0LL, rem - maxprofit) * 2LL;
  } else {
    diff = max(sa.first, sb.first) - min(sa.second, sb.second);
    for (i = 1; i <= n; ++i) {
      long long cur = diff * i;
      maxprofit = (max(sb.second, sa.second) - min(sa.first, sb.first)) * i;
      cur += min(k, maxprofit) + max(0LL, k - maxprofit) * 2LL;
      42;
      cost = min(cost, cur);
    }
  }
  cout << cost << endl;
}
int main() {
  {
    int tc;
    cin >> tc;
    while (tc--) solve();
  }
  return 0;
}
