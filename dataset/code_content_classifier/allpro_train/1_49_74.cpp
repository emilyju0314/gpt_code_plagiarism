#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn], b[maxn];
int main() {
  int n, id = 0, cnt = 0;
  scanf("%d", &n);
  long long diff = 0;
  for (int i = (1); i < (n + 1); ++i) {
    scanf("%d", &a[i]);
    if (a[i] > i) b[a[i] - i]++, cnt++;
    diff += abs(a[i] - i);
  }
  long long ans = diff;
  for (int i = (1); i < (n); ++i) {
    int last = a[n - i + 1];
    diff += last - 1 - (n - last);
    diff += n - 2 * cnt - 1;
    if (diff < ans) ans = diff, id = i;
    cnt -= b[i];
    if (last > 1) {
      cnt++;
      if (last - 1 + i <= n) b[last - 1 + i]++;
    }
  }
  cout << ans << " " << id << endl;
  return 0;
}
