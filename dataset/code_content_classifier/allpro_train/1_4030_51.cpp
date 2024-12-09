#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
template <class T>
inline bool Min(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
inline bool Max(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
inline int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
inline ll nl() {
  ll a;
  scanf("%lld", &a);
  return a;
}
inline double nd() {
  double a;
  scanf("%lf", &a);
  return a;
}
inline void pi(int a) { printf("%d ", a); }
inline void pl(ll a) { printf("%lld ", a); }
inline void pd(double a) { printf("%.12lf ", a); }
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    string s;
    cin >> s;
    int year = atoi(s.substr(4).c_str());
    int len = int(s.size()) - 4;
    int ten = 10;
    int sum = 0;
    for (int k = 1; k < len; k++) {
      sum += ten;
      ten *= 10;
    }
    while (year < 1989 + sum) year += ten;
    cout << year << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
