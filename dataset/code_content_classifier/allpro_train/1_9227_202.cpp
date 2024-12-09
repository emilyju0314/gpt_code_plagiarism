#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
string s;
int a[maxn];
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = 1e9;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'R' && s[i + 1] == 'L') ans = min(ans, (a[i + 1] - a[i]) / 2);
  }
  if (ans < 1e9)
    cout << ans << endl;
  else
    puts("-1");
  return 0;
}
