#include <bits/stdc++.h>
using namespace std;
int N, X, Y, SX, SY;
pair<int, int> v[200005];
char s[200005];
bool check(int L) {
  int p = 1, a = SX, b = SY;
  for (int i = 1; i <= N; i++) {
    if (i > L) a += v[p].first, b += v[p].second, p++;
    a -= v[i].first;
    b -= v[i].second;
    if (i >= L && abs(X - a) + abs(Y - b) <= L &&
        L % 2 == (abs(X - a) + abs(Y - b)) % 2)
      return true;
  }
  return false;
}
int main() {
  cin >> N >> s + 1 >> X >> Y;
  for (int i = 1; i <= N; i++) {
    if (s[i] == 'U')
      v[i].second++, SY++;
    else if (s[i] == 'D')
      v[i].second--, SY--;
    else if (s[i] == 'R')
      v[i].first++, SX++;
    else if (s[i] == 'L')
      v[i].first--, SX--;
  }
  if (SX == X && SY == Y) {
    cout << 0;
    return 0;
  }
  int lw = 1, hi = N, mid, last = -1;
  while (lw <= hi) {
    mid = (lw + hi) >> 1;
    if (check(mid))
      last = mid, hi = mid - 1;
    else
      lw = mid + 1;
  }
  cout << last;
  return 0;
}
