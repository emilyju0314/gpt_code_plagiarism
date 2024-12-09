#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int a[100001];
long long ans;
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++)
    for (long long j = 1; j <= m; j++)
      if ((i * i % m + j * j % m) % m == 0)
        ans = ans + (((n + m - i) / m) * ((n + m - j) / m));
  cout << ans;
  return 0;
}
