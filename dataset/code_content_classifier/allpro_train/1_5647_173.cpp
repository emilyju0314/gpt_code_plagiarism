#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long a[maxn];
long long n, p;
bool judge(long long mid) {
  int now = 1;
  for (int i = 1; i <= n; i++) {
    while (now <= n && a[now] <= mid) now++;
    if ((now - i) % p == 0) return 1;
    mid++;
  }
  return 0;
}
int main() {
  cin >> n >> p;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  long long maxi = -1;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, a[i] - i + 1);
  }
  long long r = 1000000000, l = maxi - 1;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid;
  }
  cout << l - maxi + 1 << endl;
  for (int i = maxi; i <= l; i++) cout << i << " ";
  cout << endl;
}
