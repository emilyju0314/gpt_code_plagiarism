#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int ma = 1e9 + 1;
using namespace std;
int t, l, r, cnt[26][maxn];
string str;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> str >> t;
  for (int i = 0; i < str.size(); i++) {
    cnt[str[i] - 'a'][i]++;
    for (int j = 0; j < 26; j++) {
      cnt[j][i + 1] = cnt[j][i];
    }
  }
  while (t--) {
    cin >> l >> r;
    l--;
    r--;
    if (l == r || str[l] != str[r]) {
      cout << "yes\n";
      continue;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      if (l) {
        if (cnt[i][r] - cnt[i][l - 1]) sum++;
      } else {
        if (cnt[i][r]) sum++;
      }
    }
    if (sum > 2)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
