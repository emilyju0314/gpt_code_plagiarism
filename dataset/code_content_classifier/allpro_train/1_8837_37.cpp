#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200004];
char s[200004];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  long long ans = 0;
  for (int i = 0, j = 0; i < n; i) {
    while (s[i] == s[j]) j++;
    sort(a + i, a + j);
    for (int m = max(i, j - k); m < j; m++) ans += a[m];
    i = j;
  }
  cout << ans;
  return 0;
}
