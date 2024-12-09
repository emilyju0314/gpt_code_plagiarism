#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
bool minx(S &a, const T &b) {
  return a < b ? 1 : a = b, 0;
}
template <typename T>
void int_in(T &res) {
  int flag = 1;
  char ch;
  if ((ch = getchar()) == '-')
    flag = -1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  res *= flag;
}
template <typename T>
void int_out(T a) {
  if (a > 9) int_out(a / 10);
  putchar(a % 10 + '0');
}
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int N = 1000005;
int primes[N], minp[N], a[N], left_pos[N];
int liner_sieve(int n, int primes[], int minp[]) {
  int cnt = 0;
  memset(minp, 0, n * sizeof *minp);
  for (int i = 2; i < n; ++i) {
    if (!minp[i]) {
      minp[i] = primes[cnt++] = i;
    }
    for (int j = 0; primes[j] * i < n; ++j) {
      minp[primes[j] * i] = primes[j];
      if (i % primes[j] == 0) break;
    }
  }
  return cnt;
}
vector<int> pos[N];
inline void add(int idx, int num) {
  left_pos[idx] = idx;
  for (int p = minp[num]; num != 1; p = minp[num /= p]) pos[p].push_back(idx);
}
inline void del(int idx, int num) {
  left_pos[idx] = idx;
  for (int p = minp[num]; num != 1; p = minp[num /= p]) {
    if (pos[p].size() == 0) {
      left_pos[idx] = 0;
      return;
    }
    minx(left_pos[idx], pos[p].back());
    pos[p].pop_back();
  }
}
int main() {
  int n;
  int_in(n);
  liner_sieve(N, primes, minp);
  for (int i = 1; i <= n; ++i) int_in(a[i]);
  char type;
  for (int i = 1; i <= n; ++i) {
    scanf("%c", &type);
    if (type == '*')
      add(i, a[i]);
    else
      del(i, a[i]);
  }
  vector<int> stk;
  left_pos[n + 1] = -1;
  stk.push_back(n + 1);
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    while (left_pos[stk.back()] >= left_pos[i]) {
      stk.pop_back();
    }
    if (left_pos[i] == i) ans += stk.back() - i;
    stk.push_back(i);
  }
  printf("%lld\n", ans);
  return 0;
}
