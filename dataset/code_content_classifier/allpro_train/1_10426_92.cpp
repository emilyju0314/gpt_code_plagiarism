#include <bits/stdc++.h>
using namespace std;
map<long long int, int> tut;
long long int ind, n, res = 9999999, a[10], b[10], c[1000000];
bool h[2000000], alt[10];
int hesap(long long int x) {
  int res = 0;
  long long int k = x;
  for (int i = 1; i <= ind and c[i] * c[i] <= k; i++)
    while (k % c[i] == 0) k /= c[i], res++;
  if (k != 1) res++;
  return res;
}
void rec(int nod) {
  if (nod == n + 1) {
    long long int sum = 0, k;
    for (int i = 1; i <= n; i++) {
      k = hesap(b[i]);
      sum += k + 1;
      if (k == 1 and a[i] == b[i]) sum--;
    }
    k = sum;
    if (count(alt + 1, alt + n + 1, false) > 1) sum++;
    res = min(res, sum);
    return;
  }
  alt[nod] = 0;
  b[nod] = a[nod];
  rec(nod + 1);
  for (int i = 1; i <= nod - 1; i++) {
    if (b[i] % a[nod]) continue;
    b[i] /= a[nod];
    b[nod] = a[nod];
    alt[nod] = 1;
    rec(nod + 1);
    b[i] *= a[nod];
    alt[nod] = 0;
  }
}
int main() {
  tut[1] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1, greater<long long int>());
  for (int i = 2; i <= 1000000; i++) {
    if (h[i]) continue;
    c[++ind] = i;
    for (int k = i * 2; k <= 1000000; k += i) h[k] = true;
  }
  rec(1);
  cout << res << endl;
}
