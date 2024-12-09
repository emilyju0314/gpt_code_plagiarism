#include <bits/stdc++.h>
using namespace std;
long long int i, j, k, n, m, q, t, a, b, cnt, sum, tot;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> i >> j >> a >> b;
  double dis = sqrt(((a - i) * (a - i)) + ((b - j) * (b - j)));
  cout << ceil(dis / (2 * n));
  return 0;
}
