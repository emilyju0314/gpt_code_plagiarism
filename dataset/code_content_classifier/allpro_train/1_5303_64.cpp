#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > lst;
long long mul, ans, p, q, q2;
void solve(long long pos, long long val) {
  if (pos == lst.size()) {
    const long long mod = q2;
    if (val % mod != 0) ans = max(ans, val);
    return;
  }
  long long num = 1;
  for (long long i = 0; i <= lst[pos].second; i++) {
    solve(pos + 1, val * num);
    num *= lst[pos].first;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    scanf("%lld", &p), scanf("%lld", &q);
    q2 = q;
    if (p % q != 0) {
      printf("%lld\n", p);
      continue;
    }
    mul = p;
    for (long long i = 2; i * i <= q; i++) {
      if (q % i == 0) {
        while (q % i == 0) {
          q /= i;
        }
        long long cnt = 0;
        while (mul % i == 0) {
          mul /= i;
          cnt++;
        }
        if (cnt != 0) lst.push_back(make_pair(i, cnt));
      }
    }
    if (q > 1 && mul % q == 0) {
      long long cnt = 0;
      while (mul % q == 0) {
        mul /= q;
        cnt++;
      }
      lst.push_back(make_pair(q, cnt));
    }
    ans = mul;
    solve(0, mul);
    printf("%lld\n", ans);
    lst.clear();
  }
  return 0;
}
