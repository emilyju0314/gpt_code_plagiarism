#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 100011;
const long long MAX = 1000000000000;
long long n, l, r, Ql, Qr;
long long sum[MAX_N];
long long ans;
int main(int argc, char const *argv[]) {
  while (cin >> n >> l >> r >> Ql >> Qr) {
    long long s = 0, a;
    ans = MAX;
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      s += a;
      sum[i + 1] = s;
    }
    for (int i = 0; i <= n; ++i) {
      long long t_ans = 0;
      t_ans += sum[i] * l + (sum[n] - sum[i]) * r;
      int j = n - i;
      if (j > i + 1)
        t_ans += (j - i - 1) * Qr;
      else if (i > j + 1)
        t_ans += (i - j - 1) * Ql;
      ans = ans > t_ans ? t_ans : ans;
    }
    cout << ans << endl;
  }
  return 0;
}
