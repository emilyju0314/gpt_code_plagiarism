#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
const int INF = (int)1e9 + 7;
int ini() {
  int x;
  scanf("%d", &x);
  return x;
}
long long inl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int pres[100009], s[100009];
int main() {
  int n, i, j, a, b;
  n = ini();
  a = ini();
  b = ini();
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  pres[0] = s[0];
  sort(s + 1, s + n);
  for (int i = 1; i < n; i++) {
    pres[i] = pres[i - 1] + s[i];
  }
  int res;
  int k = (s[0] * a) / pres[n - 1];
  if (k > b) {
    cout << 0 << endl;
  } else {
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
      int l = (s[0] * a) / (pres[i]);
      if (l >= b) {
        res = j;
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
