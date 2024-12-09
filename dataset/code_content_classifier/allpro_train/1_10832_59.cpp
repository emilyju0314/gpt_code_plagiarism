#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a1(n, -1);
  vector<int> a2(n, -1);
  for (int i = 0; i < 2 * n; ++i) {
    int d;
    cin >> d;
    --d;
    if (a1[d] == -1)
      a1[d] = i;
    else
      a2[d] = i;
  }
  long long ans = 0;
  int pos1 = 0;
  int pos2 = 0;
  for (int i = 0; i < n; ++i) {
    const int x = abs(a1[i] - pos1) + abs(a2[i] - pos2);
    const int y = abs(a1[i] - pos2) + abs(a2[i] - pos1);
    ans += min(x, y);
    if (x < y) {
      pos1 = a1[i];
      pos2 = a2[i];
    } else {
      pos1 = a2[i];
      pos2 = a1[i];
    }
  }
  cout << ans << endl;
  return 0;
}
