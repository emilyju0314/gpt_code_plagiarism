#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int v[260], v2[260];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  for (int i = 1; i <= n; ++i) v[i] = i;
  bool gut = 1;
  int nrr = 0;
  do {
    int sz = 0;
    ++nrr;
    for (int i = 1; i <= n; i += 2)
      if (v[i] == a && v[i + 1] == b) {
        gut = 0;
        break;
      } else if (v[i] == a || v[i] == b)
        v2[++sz] = v[i];
      else if (v[i + 1] == a || v[i + 1] == b)
        v2[++sz] = v[i + 1];
      else
        v2[++sz] = v[i];
    n /= 2;
    for (int i = 1; i <= n; ++i) v[i] = v2[i];
  } while (gut);
  if (n == 1)
    cout << "Final!" << '\n';
  else
    cout << nrr << '\n';
  return 0;
}
