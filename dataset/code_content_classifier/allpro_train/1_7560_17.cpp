#include <bits/stdc++.h>
using namespace std;
void one_case() {
  int n;
  cin >> n;
  vector<int> cnt(10);
  vector<int> rem(3), rmq(3);
  rmq[0] = 1;
  int s = 0;
  int ok = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++cnt[a];
    s += a;
    ++rem[a % 3];
    ++rmq[s % 3];
    ok |= rmq[s % 3] > 1;
  }
  if (cnt[0] == 0 || ok == 0) {
    cout << "-1\n";
    return;
  }
  string ans;
  if (s % 3) {
    if (rem[s % 3]) {
      for (int i = s % 3; i < 10; i += 3) {
        if (cnt[i]) {
          --cnt[i];
          break;
        }
      }
    } else {
      int one = 0;
      for (int i = 3 - s % 3; i < 10; i += 3) {
        if (cnt[i] > 1) {
          cnt[i] -= 2;
          break;
        }
        if (cnt[i]) {
          --cnt[i];
          if (one) {
            break;
          } else {
            one = 1;
          }
        }
      }
    }
  }
  for (int i = 9; i >= 0; --i) {
    if (i == 0 && ans.empty()) {
      cout << "0\n";
      return;
    }
    for (int j = 0; j < cnt[i]; ++j) {
      ans += '0' + i;
    }
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  while (t--) {
    one_case();
  }
  return 0;
}
