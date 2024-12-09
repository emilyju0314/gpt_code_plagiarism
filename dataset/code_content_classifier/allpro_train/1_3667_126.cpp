#include <bits/stdc++.h>
using namespace std;
int n;
char s1[200050], s2[200050];
double sum1[30], sum2[30];
int main() {
  while (cin >> n) {
    cin >> s1 + 1 >> s2 + 1;
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    double res = 0.0, tot = 0.0;
    for (int i = 1; i <= n; i++) {
      tot += 1.0 * i * i;
      int u1 = s1[i] - 'A';
      int u2 = s2[i] - 'A';
      res += sum1[u2] * (n - i + 1);
      res += sum2[u1] * (n - i + 1);
      if (u1 == u2) res += 1.0 * i * (n - i + 1);
      sum1[u1] += i;
      sum2[u2] += i;
    }
    printf("%.18f\n", res / tot);
  }
  return 0;
}
