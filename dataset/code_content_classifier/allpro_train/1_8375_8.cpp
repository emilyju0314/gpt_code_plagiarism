#include <bits/stdc++.h>
using namespace std;
char s[202000];
stack<int> t1, t2;
int l, k, k1, ans, b[202000];
struct asd {
  int num;
  int dis;
} a[202000];
bool cmp(asd z, asd x) {
  return z.num < x.num || (z.num == x.num && z.dis < x.dis);
}
int main() {
  scanf("%s", s);
  l = strlen(s);
  k = 0;
  while (k < l) {
    if (s[k] == '1') {
      if (t1.empty()) {
        ans = -1;
        break;
      } else {
        t2.push(t1.top());
        a[k + 1].num = t1.top();
        a[k + 1].dis = k + 1;
        t1.pop();
      }
    } else {
      if (!t2.empty()) {
        t1.push(t2.top());
        a[k + 1].num = t2.top();
        a[k + 1].dis = k + 1;
        t2.pop();
      } else {
        ans++;
        a[k + 1].num = ans;
        a[k + 1].dis = k + 1;
        t1.push(ans);
      }
    }
    k++;
  }
  if (!t2.empty()) ans = -1;
  printf("%d\n", ans);
  sort(a + 1, a + l + 1, cmp);
  k = 1;
  for (int i = 1; i <= ans; i++) {
    k1 = k;
    while (a[k].num == i) k++;
    printf("%d", k - k1);
    for (int j = k1; j < k; j++) printf(" %d", a[j].dis);
    printf("\n");
  }
}
