#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[100050];
map<long long, int> m;
map<long long, int> mm;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    m[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (i == 1 || a[i] != a[i - 1]) mm[a[i]] = i;
  }
  long long x = (k - 1) / n + 1;
  printf("%lld ", a[x]);
  long long y = ceil((k - (mm[a[x]] - 1) * n * 1.0) / m[a[x]]);
  printf("%lld", a[y]);
  return 0;
}
