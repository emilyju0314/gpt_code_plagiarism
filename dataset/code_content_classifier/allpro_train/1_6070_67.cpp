#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<int> vec;
    long long ans = a * n;
    for (int i = 0; i <= n; ++i) {
      if (i == 0 || i == n) {
        vec.push_back(1);
        ans += b;
      } else {
        if (s[i - 1] == '1' || s[i] == '1') {
          vec.push_back(2);
          ans += b * 2;
        } else {
          vec.push_back(1);
          ans += b;
        }
      }
    }
    vector<int> v;
    int now = 1, cnt = 1;
    for (int i = 1; i <= n + 1; ++i) {
      if (vec[i] != vec[i - 1]) {
        v.push_back(cnt);
        cnt = 1;
        now = vec[i];
      } else {
        cnt++;
      }
    }
    if (cnt != 1) v.push_back(cnt);
    int size = v.size();
    for (int i = 0; i < size; i += 2) {
      if (i == 0 || i == size - 1) continue;
      ans += min(2 * a, b * v[i]);
    }
    if (size != 1) {
      ans += 2 * a;
    }
    cout << ans << '\n';
  }
  return 0;
}
