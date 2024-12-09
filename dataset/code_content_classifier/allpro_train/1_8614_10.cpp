#include <bits/stdc++.h>
using namespace std;
long long int x[4], min_sum;
char a[3];
int m, s;
int main() {
  scanf("%I64d%I64d%I64d%I64d", &x[0], &x[1], &x[2], &x[3]);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    if (a[i] == '+') s++;
    if (a[i] == '*') m++;
  }
  sort(x, x + 4);
  if (s == 3)
    cout << (x[0] + x[1] + x[2] + x[3]);
  else if (m == 3)
    cout << (x[0] * x[1] * x[2] * x[3]);
  else if (s == 2)
    if (a[2] == '+')
      cout << (x[0] * x[1] + x[2] + x[3]);
    else
      cout << (x[0] * (x[1] + x[2] + x[3]));
  else if (s == 1)
    if (a[2] == '+') {
      min_sum = min(x[0] * x[1] * x[2] + x[3],
                    min(x[0] * x[1] + x[2] * x[3], x[0] * x[3] + x[1] * x[2]));
      cout << min_sum;
    } else if (a[0] == '+')
      cout << x[0] * x[1] * (x[2] + x[3]);
    else
      cout << x[0] * (x[1] * x[2] + x[3]);
}
