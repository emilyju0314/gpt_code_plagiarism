#include <bits/stdc++.h>
using namespace std;
long long T;
long long a, b, q;
long long sum[40005];
long long get(long long x) {
  long long ret = x / (a * b) * sum[a * b];
  ret += sum[x % (a * b)];
  return ret;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> a >> b >> q;
    if (a > b) swap(a, b);
    sum[0] = 0;
    for (int i = 1; i <= a * b; i++) {
      sum[i] = sum[i - 1];
      if (i % a % b != i % b % a) sum[i]++;
    }
    long long l, r;
    for (int i = 0; i < q; i++) {
      cin >> l >> r;
      cout << get(r) - get(l - 1) << " ";
    }
    cout << endl;
  }
  return 0;
}
