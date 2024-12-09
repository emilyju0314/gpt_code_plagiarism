#include <bits/stdc++.h>
using namespace std;
int n, r, a[1000005], z, g;
long long sum;
int main() {
  scanf("%d %d", &n, &r);
  for (int i = 1; i <= (1 << n); i++) {
    scanf("%d", a + i);
    sum += (long long)a[i];
  }
  int div = (1 << n);
  double ans = (double)sum / (double)div;
  printf("%.10f\n", ans);
  for (int i = 1; i <= r; i++) {
    cin >> z >> g;
    z++;
    sum -= (long long)a[z];
    a[z] = g;
    sum += (long long)a[z];
    ans = (double)sum / (double)div;
    printf("%.10f\n", ans);
  }
}
