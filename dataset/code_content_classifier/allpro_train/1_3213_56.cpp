#include <bits/stdc++.h>
using namespace std;
long long limit = 4294967296;
template <typename T>
void print(const T& x) {
  cerr << x << ' ';
}
template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest) {
  print(first);
  print(rest...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long ara[n + 2];
  for (long long i = 0; i < n; i++) cin >> ara[i];
  sort(ara, ara + n);
  long long l = 0, h = 2000000000, mid = 0, res = 0;
  while (l != h) {
    mid = (l + h + 1) / 2;
    long long moves = 0, d = mid;
    for (long long i = n / 2; i < n; i++) {
      if (d - ara[i] > 0) moves += (d - ara[i]);
    }
    if (moves <= k) {
      l = mid;
      res = l;
    } else {
      h = mid - 1;
    }
  }
  cout << res << endl;
  return 0;
}
