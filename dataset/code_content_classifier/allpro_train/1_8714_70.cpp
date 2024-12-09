#include <bits/stdc++.h>
using namespace std;
int __sum() { return 0; }
template <typename T, typename... Args>
T __sum(T a, Args... args) {
  return a + __sum(args...);
}
unsigned long long arr2int(int a[], int n) {
  unsigned long long x = 0;
  for (int i = 0; i < n; ++i) x = ((unsigned long long)a[i] + x * 10);
  return x;
}
long long Combination(long long n, long long r) {
  if (r > n / 2) r = n - r;
  long long ans = 1;
  long long i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long go(long long a, long long b) {
  if (a <= 0 || b <= 0) {
    return 0;
  }
  return 1 + max(go(a - 2, b + 1), go(a + 1, b - 2));
}
int main() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int qs[n];
  memset((qs), 0, sizeof(qs));
  ;
  for (long long int i = 0; i < n; ++i) {
    if (s[i] == 'Q') {
      if (i == 0)
        qs[i] = 1;
      else
        qs[i] = qs[i - 1] + 1;
    } else {
      if (i == 0)
        qs[i] = 0;
      else {
        qs[i] = qs[i - 1];
      }
    }
  }
  long long int ans = 0;
  for (long long int i = 1; i < n - 1; i++) {
    if (s[i] == 'A') {
      ans += qs[i - 1] * (qs[n - 1] - qs[i]);
    }
  }
  cout << ans;
  return 0;
}
