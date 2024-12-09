#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long INF64 = 1e18;
const long long INF32 = 1e9;
const long long MOD = 1e9 + 7;
const long double PI = acos(-1.0L);
const long double EPS = static_cast<long double>(1e-9);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  {
    long long n;
    cin >> n;
    pair<long long, long long> a[n];
    for (long long i = (0); i < (n); i++) {
      cin >> a[i].first;
      a[i].second = i + 1;
    }
    sort(a, a + n);
    cout << (n + 1) / 2 << endl;
    for (long long i = 0; i < n; i += 2) cout << a[i].second << ' ';
    cout << endl << n / 2 << endl;
    for (long long i = 1; i < n; i += 2) cout << a[i].second << ' ';
    cout << endl;
  }
  return 0;
}
