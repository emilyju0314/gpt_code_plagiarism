#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, ans = 0, tmp = 1;
  int n;
  char s1[500050], s2[500050];
  cin >> n >> k;
  scanf("%s%s", s1, s2);
  for (int i = 0; i < n; i++) {
    tmp = tmp << 1;
    if (s2[i] == 'a') tmp--;
    if (s1[i] == 'b') tmp--;
    if (tmp >= k) {
      ans += (n - i) * k;
      break;
    }
    ans += tmp;
  }
  cout << ans;
  return 0;
}
