#include <bits/stdc++.h>
using namespace std;
ifstream fi("609C.INP");
ofstream fo("609C.OUT");
int n, sum = 0, a[100005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  int tmp = sum % n;
  sum /= n;
  for (int i = n; tmp > 0 && i >= 0; i--, tmp--) a[i]--;
  long long res = 0;
  for (int i = 1; i <= n; i++) res += abs(sum - a[i]);
  cout << res / 2;
}
