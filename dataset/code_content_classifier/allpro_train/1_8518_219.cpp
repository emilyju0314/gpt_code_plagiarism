#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, i, j, k, st, res, a[N], b[N], q1, q2;
char s1[N], s2[N];
int main() {
  scanf("%s%s", s1, s2);
  n = strlen(s1);
  m = strlen(s2);
  for (i = 0; i < n; ++i) {
    a[i + 1] = s1[i] - '0';
    q1 += a[i + 1];
  }
  for (i = 0; i < m; ++i) {
    b[i + 1] = s2[i] - '0';
    q2 += b[i + 1];
  }
  if (q1 % 2 == 1) q1++;
  if (q1 >= q2)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
