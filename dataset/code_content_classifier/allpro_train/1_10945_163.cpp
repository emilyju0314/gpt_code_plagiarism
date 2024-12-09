#include <bits/stdc++.h>
using namespace std;
int c1, c2, c3, c4, n, m, a[1001], b[1001], suma[1001], sumb[1001];
int auFull, tuFull, answer;
int main() {
  scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    suma[i] = c1 * a[i];
    if (c2 <= suma[i]) suma[i] = c2;
    auFull += suma[i];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
    sumb[i] = c1 * b[i];
    if (c2 <= sumb[i]) sumb[i] = c2;
    tuFull += sumb[i];
  }
  if (auFull >= c3) auFull = c3;
  if (tuFull >= c3) tuFull = c3;
  answer = auFull + tuFull;
  if (answer >= c4) answer = c4;
  printf("%d", answer);
  return 0;
}
