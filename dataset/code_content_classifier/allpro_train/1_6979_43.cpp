#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
const long long INF = INT_MAX;
const long long mod = 1e9 + 7;
const long long LINF = 1e14;
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(101, -1);
  for (long long i = 0; i < (m); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x] = y;
  }
  if (v[n] != -1) return cout << v[n] << endl, 0;
  for (long long i = (1); i < (101); i++) {
    bool pos = true;
    for (long long j = (1); j < (101); j++)
      if (j != n && v[j] != -1 && v[j] != (j - 1) / i + 1) pos = false;
    if (pos && v[n] == -1)
      v[n] = (n - 1) / i + 1;
    else if (pos && v[n] != (n - 1) / i + 1)
      return cout << -1 << endl, 0;
  }
  cout << v[n] << endl;
  return 0;
}
