#include <bits/stdc++.h>
using namespace std;
long long a[1001001];
long long b[1001001];
int main() {
  long long n, k;
  cin >> n;
  long long s = 0;
  for (long long i = 0; i < 1001001; i++) a[i] = 0;
  long long num = 0;
  a[num++] = n;
  while (1) {
    k = a[num - 1];
    while (k > 0) {
      k /= 2;
      s++;
    }
    k = 1;
    while (--s) k = 2 * k + 1;
    a[num] = k - a[num - 1] - 1;
    num++;
    if (a[num - 1] <= 0) break;
  }
  long long ind = 0;
  if (a[num - 1] == 0) b[ind++] = 0;
  for (long long i = num - 1; i > 0; i--)
    for (long long j = a[i - 1]; j > a[i]; j--) b[ind++] = j;
  long long ans = 0;
  for (long long i = 0; i < ind; i++) ans += b[i] ^ i;
  cout << ans << endl;
  for (long long i = 0; i < ind; i++) cout << b[i] << " ";
  return 0;
}
