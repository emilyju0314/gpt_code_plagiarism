#include <bits/stdc++.h>
using namespace std;
int n;
long long a[300010], b[300010];
long long sum[300010];
long long sum_s[2 * 300010];
long long sum_n[2 * 300010];
long long sumr[300010];
long long suml[300010];
void table() {
  for (int i = n; i >= 1; i--) sum[i] = sum[i + 1] + a[i] + b[i];
  for (int i = 1; i <= n; i++) {
    sum_s[i] = sum_s[i - 1] + a[i] * (i - 1);
    sum_n[i] = sum_n[i - 1] + b[i] * (i - 1);
  }
  for (int i = n; i >= 1; i--) {
    sum_s[2 * n - i + 1] = sum_s[2 * n - i] + b[i] * (2 * n - i);
    sum_n[2 * n - i + 1] = sum_n[2 * n - i] + a[i] * (2 * n - i);
  }
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      sumr[i] = sum_s[2 * n - i + 1] - sum_s[i - 1] + sum[i] * (i - 1);
      suml[i] = suml[i - 1] + a[i - 1] * (2 * i - 3) + b[i - 1] * (2 * i - 4);
    } else {
      sumr[i] = sum_n[2 * n - i + 1] - sum_n[i - 1] + sum[i] * (i - 1);
      suml[i] = suml[i - 1] + a[i - 1] * (2 * i - 4) + b[i - 1] * (2 * i - 3);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  table();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, sumr[i] + suml[i]);
  }
  cout << ans << endl;
  return 0;
}
