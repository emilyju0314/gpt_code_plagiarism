#include <bits/stdc++.h>
const int N = 105;
const int mod = 1e9 + 7;
using namespace std;
string s;
int n, k;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int po(int n, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1LL * ans * n % mod;
    n = 1LL * n * n % mod;
    k >>= 1;
  }
  return ans;
}
struct fibo {
  int siz, num, cnt[N][N];
  void init() {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) cnt[i][j] = 0;
  }
  void Merge(fibo& x, fibo& y) {
    init();
    siz = (x.siz + y.siz) % mod;
    num = (x.num + y.num) % (mod - 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        for (int k = i; k < j; k++) {
          add(cnt[i][j], 1LL * x.cnt[i][k] * y.cnt[k + 1][j] % mod);
        }
        int l = ((i == 1) ? po(2, x.num) : 1);
        int r = ((j == n) ? po(2, y.num) : 1);
        add(cnt[i][j], 1LL * l * y.cnt[i][j] % mod);
        add(cnt[i][j], 1LL * r * x.cnt[i][j] % mod);
      }
    }
  }
} a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> s;
  a.init();
  b.init();
  a.siz = b.siz = a.num = b.num = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      b.cnt[i + 1][i + 1] = 1;
    else
      a.cnt[i + 1][i + 1] = 1;
  }
  for (int i = 1; i < k; i++) {
    fibo New;
    New.Merge(a, b);
    b = a;
    a = New;
  }
  if (k)
    cout << a.cnt[1][n];
  else
    cout << b.cnt[1][n];
}
