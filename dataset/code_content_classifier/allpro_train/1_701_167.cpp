#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
vector<int> a[2];
char ss[maxn];
int main() {
  int n;
  scanf("%d%s", &n, ss);
  long long ans = 1LL * n * (n + 1) / 2 - n;
  for (int i = 0; i < n; i++) {
    int k = ss[i] - 'A';
    if (a[!k].size() > 0) {
      int p = a[!k].back();
      if (p == i - 1) {
        if (a[k].size() > 0) {
          int len = p - a[k].back();
          ans -= len;
        } else {
          ans -= p + 1;
        }
      } else {
        ans--;
      }
    }
    a[k].push_back(i);
  }
  printf("%lld\n", ans);
  return 0;
}
