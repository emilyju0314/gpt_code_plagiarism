#include <bits/stdc++.h>
using namespace std;
long n, num, a[200100], povecanja[200100], op, x, vr, el, i;
long long suma;
double prosek;
int main() {
  num = 1;
  a[1] = 0;
  prosek = 0;
  suma = 0;
  scanf("%ld", &n);
  for (i = 1; i <= n; i++) povecanja[i] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%ld", &op);
    if (op == 1) {
      scanf("%ld %ld", &x, &vr);
      povecanja[x] += vr;
      suma = suma + vr * x;
    } else if (op == 2) {
      scanf("%ld", &el);
      num++;
      a[num] = el;
      suma += el;
    } else {
      suma = suma - povecanja[num] - a[num];
      povecanja[num - 1] += povecanja[num];
      povecanja[num] = 0;
      num--;
    }
    prosek = double(suma) / double(num);
    printf("%.8lf\n", prosek);
  }
  return 0;
}
