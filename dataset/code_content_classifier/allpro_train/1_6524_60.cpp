#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
long long int n;
pair<long long int, int> factor[100];
long long int tot[100];
int m = 0;
long long int ans;
bool f(long long int a) {
  if (a <= 0 || a & 1) return true;
  return false;
}
void check(long long int a, long long int b, long long int c) {
  if (f(b + c - a) || f(c + a - b) || f(a + b - c))
    ;
  else
    ++ans;
}
void dfs(int d, long long int a, long long int b, long long int c) {
  if (d == m) {
    check(a, b, c);
    return;
  }
  long long int mul1 = 1;
  for (int i = 0; i < factor[d].second + 1; ++i) {
    long long int mul2 = 1;
    for (int j = 0; j < factor[d].second + 1 - i; ++j) {
      long long int mul3 = tot[d] / mul1 / mul2;
      dfs(d + 1, a * mul1, b * mul2, c * mul3);
      mul2 *= factor[d].first;
    }
    mul1 *= factor[d].first;
  }
}
int main() {
  cin >> n;
  if (n % 3) {
    puts("0");
    return 0;
  }
  n /= 3;
  long long int t = n;
  for (long long int i = 2; i * i <= t; ++i)
    if (t % i == 0) {
      factor[m].first = i;
      long long int tmp = 1;
      while (t % i == 0) {
        t /= i;
        tmp *= i;
        factor[m].second++;
      }
      tot[m] = tmp;
      ++m;
    }
  if (t > 1) factor[m++] = make_pair(t, 1), tot[m - 1] = t;
  ;
  dfs(0, 1, 1, 1);
  cout << ans << endl;
  return 0;
}
