#include <bits/stdc++.h>
using namespace std;
struct dbg_ {
  template <typename T>
  dbg_& operator,(const T& x) {
    cerr << x << ' ';
    return *this;
  }
} dbg_t;
struct cin_ {
  template <typename T>
  cin_& operator,(T& x) {
    cin >> x;
    return *this;
  }
} cin_;
template <typename T1, typename T2>
static inline ostream& operator<<(ostream& os, std::pair<T1, T2> const& p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n;
int A[((int)1e2 + 7)];
int DP[((int)1e2 + 7)][3];
int dp(int day, int o) {
  if (day == n) return 0;
  if (DP[day][o] != -1) return DP[day][o];
  int lemin = 2000000007;
  if (o != 1 && (A[day] == 2 || A[day] == 3))
    (lemin) = min((lemin), (dp(day + 1, 1)));
  if (o != 2 && (A[day] == 1 || A[day] == 3))
    (lemin) = min((lemin), (dp(day + 1, 2)));
  (lemin) = min((lemin), (dp(day + 1, 0) + 1));
  DP[day][o] = lemin;
  return lemin;
}
int main() {
  memset(DP, -1, sizeof(DP));
  { cin_, n; };
  for (int i = 0, _i = (n); i < _i; ++i) {
    cin >> A[i];
  };
  cout << dp(0, 0) << endl;
  return 0;
}
