#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)8e18;
int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  vector<long long> v(n);
  for (int i = int(0); i < int(n); i++) {
    scanf("%lld", &v[i]);
  }
  sort(v.begin(), v.end());
  long long ans = (v[n / 2 - 1] - v[0]) * (v.back() - v[n / 2]);
  long long half = n / 2;
  for (int i = int(1); i < int(n - 1); i++) {
    long long ending = i + half - 1;
    if (ending >= n - 1) {
      break;
    }
    ans = min(ans, (v.back() - v[0]) * (v[ending] - v[i]));
  }
  printf("%lld\n", ans);
  return 0;
}
