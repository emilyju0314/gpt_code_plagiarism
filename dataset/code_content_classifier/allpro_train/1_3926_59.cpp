#include <bits/stdc++.h>
using namespace std;
int k, b, n, a[111111], s, o;
map<int, int> w;
long long ans = 0, aa;
int f(int x) { return x % (k - 1); }
int main() {
  cin >> k >> b >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  w[0]++;
  for (int i = 0; i < n; i++) {
    s += a[i];
    s = f(s);
    o = s - b;
    if (o < 0) o += k - 1;
    ans += w[o];
    w[s]++;
  }
  s = 0;
  for (int i = 0; i < n; i++) {
    if (a[i])
      s = 0;
    else
      s++;
    aa += s;
  }
  if (b == 0)
    ans = aa;
  else if (b == k - 1)
    ans -= aa;
  cout << (ans) << endl;
  return 0;
}
