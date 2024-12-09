#include <bits/stdc++.h>
using namespace std;
long long arr[1007];
int main() {
  long long n, m, x;
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    cin >> x;
    if (n <= m) arr[i] = x;
  }
  if (n > m)
    cout << 0 << endl;
  else {
    sort(arr + 1, arr + n + 1);
    long long s = 1;
    for (long long i = n; i > 1; --i) {
      long long val = arr[i];
      for (long long j = i - 1; j >= 1; --j) {
        long long val1 = arr[j];
        long long v = abs(val - val1) % m;
        s = ((s % m) * (v % m)) % m;
      }
    }
    cout << s << endl;
  }
}
