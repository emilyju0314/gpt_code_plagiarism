#include <bits/stdc++.h>
using namespace std;
int n, A[200005];
int cnt[200005];
void add(int x) {
  while (x < 200005) {
    cnt[x]++;
    x += x & -x;
  }
}
int query(int x) {
  int ans = 0;
  if (x >= 200005) x = 200005 - 1;
  while (x) {
    ans += cnt[x];
    x -= x & -x;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    add(A[i]);
  }
  sort(A + 1, A + 1 + n);
  int last = 0;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (A[i] == last) continue;
    last = A[i];
    long long res = 0;
    for (int j = last; j <= A[n]; j += last) {
      int R = j + last - 1;
      int sum = query(R) - query(j - 1);
      res += 1ll * j * sum;
    }
    if (ans < res) ans = res;
  }
  cout << ans << endl;
  return 0;
}
