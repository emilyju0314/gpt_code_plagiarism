#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long n, a[(110)], k;
long long calc(long long d) {
  long long p = 0;
  for (int i = 1; i <= n; i++) {
    p += (a[i] % d + d) % d;
  }
  return p;
}
bool check(long long d) {
  if (d < 0) return 0;
  long long p = 0;
  for (int i = 1; i <= n; i++) {
    p += (a[i] % d + d) % d;
  }
  return p <= k;
}
long long work(long long l, long long r) {
  long long ans = -1;
  if (l > r) return ans;
  if (l == r) {
    if (check(l)) ans = l;
    return ans;
  }
  long long p = calc(l), delta = calc(l + 1) - p;
  long long mm;
  if (!delta) {
    mm = r;
  } else {
    long long c = (k - p) / (delta);
    mm = min(l + c, r);
  }
  if (check(mm)) ans = mm;
  return ans;
}
vector<long long> S;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) a[i] = -a[i];
  long long ans = 0, nxt;
  for (int i = 1; i <= n; i++) {
    long long nxt = 1;
    for (long long pre = 1; pre <= -a[i]; pre = nxt + 1) {
      nxt = a[i] / (a[i] / pre);
      S.push_back(nxt);
    }
  }
  S.push_back(1);
  sort((S).begin(), (S).end());
  S.erase(unique((S).begin(), (S).end()), S.end());
  vector<long long>::reverse_iterator it;
  work(35, 36);
  long long pre = *S.rbegin();
  for (it = S.rbegin(); it != S.rend(); it++) {
    if (check(pre)) {
      ans = pre;
      break;
    }
    long long nxt = *it;
    long long p = work(nxt + 1, pre);
    if (p != -1) {
      ans = max(ans, p);
      break;
    }
    pre = nxt;
  }
  if (check(1)) ans = max(ans, 1LL);
  long long tot = -a[n] * n;
  for (int i = 1; i <= n; i++) tot -= -a[i];
  if (tot <= k) {
    long long p = (k - tot) / n;
    if (check(-a[n] + p)) ans = max(ans, -a[n] + p);
  }
  cout << ans << endl;
  return 0;
}
