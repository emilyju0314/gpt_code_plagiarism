#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int n, a[500000], mi, num1[500000], num2[500000], s[500000], ans, ansl, ansr,
    cnt;
char ss[500000];
void deal(int lab) {
  int m1, m2;
  auto x = lower_bound(v1.begin(), v1.end(), lab);
  if (x != v1.end()) {
    m1 = *x;
    if (num1[m1] - num1[lab - 1] > ans) {
      ans = num1[m1] - num1[lab - 1];
      ansl = lab;
      ansr = m1;
    }
  }
  x = lower_bound(v2.begin(), v2.end(), lab);
  if (x != v2.end()) {
    m2 = *x;
    if (m2 > m1) return;
    if (num2[m2] - num2[lab - 1] + cnt > ans) {
      ans = num2[m2] - num2[lab - 1] + cnt;
      ansl = lab;
      ansr = m2;
    }
  }
}
int main() {
  mi = 0x5fffffff;
  scanf("%d%s", &n, ss);
  for (int i = 0; i < n; i++) {
    a[i + 1] = ss[i] == '(' ? 1 : -1;
    s[i + 1] = s[i] + a[i + 1];
    mi = min(mi, s[i + 1]);
    cnt += a[i + 1];
  }
  if (cnt != 0) {
    printf("0\n1 1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    num1[i] = num1[i - 1];
    num2[i] = num2[i - 1];
    if (s[i] == mi) v1.push_back(i), cnt++;
    if (s[i] == mi + 1) v2.push_back(i), num1[i]++;
    if (s[i] == mi + 2) num2[i]++;
  }
  ans = cnt;
  ansl = ansr = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) deal(i);
  }
  int m1 = v1[0], m2 = *(--v1.end()) + 1;
  if (m2 <= n && m2 > m1 &&
      (num1[m1 - 1] - num1[0] + num1[n] - num1[m2 - 1]) > ans) {
    ans = num1[m1 - 1] - num1[0] + num1[n] - num1[m2 - 1];
    ansl = m1;
    ansr = m2;
  }
  m1 = v2[0];
  if (m2 <= n) {
    m2 = *(--v2.end());
    m2++;
    if (m2 <= n && (num2[n] - num2[m2 - 1] + num2[m1 - 1] + cnt) > ans)
      ans = num2[n] - num2[m2 - 1] + num2[m1 - 1] + cnt, ansl = m1, ansr = m2;
  }
  printf("%d\n%d %d", ans, ansl, ansr);
}
