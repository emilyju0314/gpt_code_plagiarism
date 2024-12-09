#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
const int maxi = 1e6 + 6;
long long a[maxi], x[maxi], b[maxi];
int n;
long long t;
int sum[maxi];
int los[maxi];
int ll[maxi];
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
    sum[x[i] - 1]++;
    sum[i - 1]--;
  }
  for (int i = n; i > 0; i--) sum[i] += sum[i + 1];
  for (int i = 1; i <= n; i++)
    if (x[i] < i) return !printf("No\n");
  for (int i = 1; i <= n; i++)
    if (sum[i] > 0)
      b[i] = a[i + 1] + t;
    else
      b[i] = a[i] + t;
  for (int i = 2; i <= n; i++)
    if (b[i] <= b[i - 1]) b[i] = b[i - 1] + 1;
  for (int i = 2; i <= n; i++)
    if (a[i] + t > b[i - 1]) los[i] = 1;
  for (int i = 1; i <= n; i++) ll[i] = ll[i - 1] + los[i];
  for (int i = 1; i <= n; i++)
    if (x[i] < n && x[i] - i > 0 && ll[x[i] + 1] - ll[i] == 0)
      return !printf("No\n");
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
  printf("\n");
  return 0;
}
