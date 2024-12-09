#include <bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    b[i] = abs(a[i] - a[i + 1]);
  }
  long long sum = 0, summ = 0;
  long long ans = -1;
  for (int i = 1; i < n; i++) {
    int temp = b[i];
    if (i % 2 == 0) temp = -temp;
    summ += temp;
    sum += temp;
    ans = max(ans, sum);
    ans = max(ans, -summ);
    if (sum < 0) sum = 0;
    if (summ > 0) summ = 0;
  }
  cout << ans << endl;
}
