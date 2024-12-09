#include <bits/stdc++.h>
using namespace std;
pair<int, int> v[4];
int calcArea(int i, int j) {
  int ans = max(v[i].second, v[j].second) - min(v[i].second, v[j].second);
  ans *= max(v[i].first, v[j].first) - min(v[i].first, v[j].first);
  if (ans < 0) ans *= -1;
  return ans;
}
int main(int argc, char** argv) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  int ans = -1;
  if (n == 2) {
    if (v[0].first == v[1].first || v[0].second == v[1].second)
      ans = -1;
    else
      ans = calcArea(0, 1);
  } else if (n > 2) {
    for (int i = 0; i < n && ans == -1; i++) {
      for (int j = i + 1; j < n && ans == -1; j++) {
        if (v[i].first != v[j].first && v[i].second != v[j].second)
          ans = calcArea(i, j);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
