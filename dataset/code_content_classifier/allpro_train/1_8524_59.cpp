#include <bits/stdc++.h>
using namespace std;
long long let[26];
int main() {
  long long n, m, acc = 0;
  long long ans = 0;
  char ch;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf(" %c", &ch);
    let[tolower(ch) - 'a']--;
  }
  sort(let, let + 26);
  for (const auto el : let) {
    if (acc + -1 * el <= m)
      acc += -1 * el, ans += (-el) * (-el);
    else if (acc + -1 * el > m) {
      ans += (m - acc) * (m - acc);
      acc += (m - acc);
    }
    if (acc == m) break;
  }
  cout << ans << '\n';
  return 0;
}
