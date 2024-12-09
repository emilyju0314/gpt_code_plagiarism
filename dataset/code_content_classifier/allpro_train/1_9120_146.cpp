#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v(2 * n + 1);
  for (int i = 0; i < 2 * n + 1; ++i) {
    cin >> v[i];
  }
  int cnt = 0;
  for (int i = 0; i < 2 * n + 1; ++i) {
    if (i == 0 || i == 2 * n) continue;
    if (cnt == k) {
      break;
    } else {
      if (v[i] - v[i - 1] > 1 && v[i] - v[i + 1] > 1) {
        cnt++;
        v[i]--;
      }
    }
  }
  for (int i = 0; i < 2 * n + 1; ++i) {
    cout << v[i] << " ";
  }
  return 0;
}
