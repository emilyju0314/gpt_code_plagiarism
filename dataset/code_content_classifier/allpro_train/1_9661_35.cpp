#include <bits/stdc++.h>
using namespace std;
double Inf = 1e50;
const int Maxn = 1020;
double d[Maxn];
bool done[Maxn];
int n;
int pro[Maxn][Maxn];
double nowp[Maxn], nowval[Maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) scanf("%d", &pro[i][j]);
  }
  for (int i = 1; i <= n; i++) d[i] = Inf;
  for (int i = 1; i <= n; i++) nowp[i] = 1;
  d[n] = 0;
  for (int i = 1; i <= n; i++) {
    int cs = -1;
    for (int j = 1; j <= n; j++) {
      if (done[j]) continue;
      if (cs == -1 || d[j] < d[cs]) cs = j;
    }
    done[cs] = 1;
    for (int j = 1; j <= n; j++) {
      if (done[j]) continue;
      nowval[j] += nowp[j] * pro[j][cs] / 100.0 * (d[cs] + 1.0);
      nowp[j] *= 1.0 - pro[j][cs] / 100.0;
      d[j] = (nowval[j] + nowp[j]) / (1.0 - nowp[j]);
    }
  }
  printf("%.12f\n", d[1]);
}
