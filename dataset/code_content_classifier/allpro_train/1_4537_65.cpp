#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5 + 10;
int prime[maxx], vis[maxx];
int cnt;
long long gcd(long long a, long long b) {
  return a % b == 0 ? b : gcd(b, a % b);
}
void get_prime() {
  cnt = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 2; i < maxx; i++) {
    if (!vis[i]) {
      prime[cnt++] = i;
      for (int j = 2 * i; j < maxx; j += i) {
        vis[j] = 1;
      }
    }
  }
}
bool judge(int temp) {
  if (temp < maxx) {
    return !vis[temp];
  }
  for (int i = 0; i < cnt && prime[i] <= temp; i++) {
    if (temp % prime[i] == 0) {
      return false;
    }
  }
  return true;
}
long long get_v(int n) {
  for (int i = n; i >= 2; i--) {
    if (judge(i)) {
      return i;
    }
  }
  return 0;
}
long long get_u(int n) {
  for (int i = n + 1; i; i++) {
    if (judge(i)) {
      return i;
    }
  }
  return 0;
}
int main() {
  get_prime();
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long v = get_v(n);
    long long u = get_u(n);
    long long p = u * v + 2 * (n - u - v + 1);
    long long q = 2 * u * v;
    long long mod = gcd(p, q);
    printf("%lld/%lld\n", p / mod, q / mod);
  }
}
