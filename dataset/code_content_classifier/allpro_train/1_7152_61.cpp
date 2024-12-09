#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct Node {
  int a, b, d;
} p[MAXN];
int n, k;
bool cmp(Node aa, Node bb) { return aa.d < bb.d; }
bool cmp2(Node aa, Node bb) { return aa.d > bb.d; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].a);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i].b);
    p[i].d = p[i].a - p[i].b;
  }
  long long ans = 0;
  sort(p + 1, p + 1 + n, cmp);
  if (p[1].d >= 0) {
    for (int i = 1; i <= k; i++) ans += (long long)p[i].a;
    for (int i = k + 1; i <= n; i++) ans += (long long)p[i].b;
  } else if (p[n].d <= 0) {
    sort(p + 1, p + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
      ans += (long long)p[i].a;
    }
  } else {
    if (p[k].d <= 0) {
      for (int i = 1; i <= n; i++) {
        if (p[i].d <= 0)
          ans += (long long)p[i].a;
        else
          ans += (long long)p[i].b;
      }
    } else {
      int tmp = 0;
      for (int i = 1; i <= n; i++) {
        if (p[i].d <= 0) {
          ans += (long long)p[i].a;
        } else {
          tmp = i;
          break;
        }
      }
      sort(p + tmp, p + 1 + k, cmp2);
      for (int i = tmp; i <= k; i++) {
        ans += (long long)p[i].a;
      }
      for (int i = k + 1; i <= n; i++) {
        ans += (long long)p[i].b;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
