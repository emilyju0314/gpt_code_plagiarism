#include <bits/stdc++.h>
using namespace std;
long int num[100005];
long long int bits[50];
int bitcnt(long int x) {
  int ans = 0;
  while (x != 0) {
    if (x % 2 != 0) ans++;
    x /= 2;
  }
  return ans;
}
int main() {
  int N, i, B, mx;
  long long int ans;
  while (scanf("%d", &N) != EOF) {
    for (i = 0; i < N; i++) scanf("%ld", &num[i]);
    for (i = 0; i < 50; i++) bits[i] = 0;
    mx = 0;
    for (i = 0; i < N; i++) {
      B = bitcnt(num[i]);
      bits[B]++;
      mx = (B > mx ? B : mx);
    }
    ans = 0;
    for (i = 0; i <= mx; i++) {
      ans += ((bits[i] * (bits[i] - 1)) / 2);
    }
    cout << ans << endl;
  }
  return 0;
}
