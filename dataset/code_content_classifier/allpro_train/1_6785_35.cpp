#include <bits/stdc++.h>
using namespace std;
map<long long, int> last;
int b[1000000];
long long a[100000];
long long d[100][2];
pair<long long, long long> solve(long long x, long long y) {
  long long xx, yy;
  pair<long long, long long> ans;
  if (x == 1) {
    return make_pair(1, 0);
  }
  xx = x;
  yy = y % x;
  if (yy == 1) {
    ans = make_pair(1, xx - 1);
  } else {
    ans = solve(xx % yy, yy);
    ans.second += (xx / yy) * ans.first;
    ans.first %= yy;
    ans.second %= xx;
  }
  ans.first += (y / x) * ans.second;
  ans.first %= y;
  ans.second %= x;
  return ans;
}
long long inv(long long x, long long y) {
  x %= y;
  pair<long long, long long> p = solve(x, y);
  return p.first;
}
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  vector<long long> primes;
  long long i, j, k, l;
  long long m, n, now, tmp, tmp1, cnt, b1, nn, ans, all;
  memset(b, 0, sizeof(b));
  primes.clear();
  for (i = 2; i < 1000000; i++) {
    if (b[i] == 0) {
      primes.push_back(i);
      for (j = i + i; j < 1000000; j += i) b[j] = 1;
    }
  }
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (i = 0; i < k; i++) scanf("%I64d", &a[i]);
  last.clear();
  now = 1;
  for (i = 0; i < k; i++) {
    tmp = gcd(now, a[i]);
    now /= tmp;
    if ((1LL << 60) / now < a[i]) {
      printf("NO\n");
      return 0;
    }
    now *= a[i];
    if (now > n) {
      printf("NO\n");
      return 0;
    }
    tmp = a[i];
    for (j = 0; j < primes.size() && primes[j] * primes[j] <= tmp; j++) {
      cnt = 0;
      while (tmp % primes[j] == 0) {
        tmp /= primes[j];
        cnt++;
      }
      tmp1 = 1;
      for (l = 0; l < cnt; l++) {
        tmp1 *= primes[j];
        if (i - tmp1 >= 0) {
          if ((last.find(tmp1) == last.end()) || (last[tmp1] != i - tmp1)) {
            printf("NO\n");
            return 0;
          }
          last[tmp1] = i;
        } else {
          if (last.find(tmp1) != last.end()) {
            printf("NO\n");
            return 0;
          }
          last[tmp1] = i;
        }
      }
    }
    if (tmp > 1) {
      tmp1 = tmp;
      if (i - tmp1 >= 0) {
        if ((last.find(tmp1) == last.end()) || (last[tmp1] != i - tmp1)) {
          printf("NO\n");
          return 0;
        }
        last[tmp1] = i;
      } else {
        if (last.find(tmp1) != last.end()) {
          printf("NO\n");
          return 0;
        }
        last[tmp1] = i;
      }
    }
  }
  for (map<long long, int>::iterator it = last.begin(); it != last.end();
       it++) {
    if (it->second + it->first < k) {
      printf("NO\n");
      return 0;
    }
  }
  nn = 0;
  for (map<long long, int>::reverse_iterator it = last.rbegin();
       it != last.rend(); it++) {
    b1 = 1;
    for (i = 0; i < nn; i++)
      if (d[i][0] % it->first == 0) {
        b1 = 0;
        break;
      }
    if (b1 == 0) continue;
    d[nn][0] = it->first;
    d[nn][1] = k - 1 - it->second;
    nn++;
  }
  ans = 0;
  all = 1;
  for (i = 0; i < nn; i++) all *= d[i][0];
  for (i = 0; i < nn; i++) {
    tmp = 1;
    for (j = 0; j < nn; j++)
      if (j != i) tmp *= d[j][0];
    tmp *= inv(tmp, d[i][0]);
    tmp *= d[i][1];
    tmp %= all;
    ans += tmp;
  }
  ans %= all;
  if (ans - (k - 1) <= 0) ans += all;
  if (ans <= m) {
    printf("YES\n");
  } else
    printf("NO\n");
}
