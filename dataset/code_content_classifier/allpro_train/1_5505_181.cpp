#include <bits/stdc++.h>
using namespace std;
bool ahasan(int a, int b) { return a > b; }
int main() {
  long long int n, n1, n2, i, j, k, a[100008] = {0}, sum = 0;
  double avg1 = 0, avg2 = 0;
  cin >> n >> n1 >> n2;
  if (n1 < n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
  }
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, ahasan);
  for (i = 0; i < n2; i++) {
    sum = sum + a[i];
  }
  avg1 = (double)sum / n2;
  sum = 0;
  for (i = n2; i < n1 + n2; i++) {
    sum = sum + a[i];
  }
  avg2 = (double)sum / n1;
  printf("%lf\n", avg1 + avg2);
  return 0;
}
