#include <bits/stdc++.h>
using namespace std;
const long long size = 40;
const size_t modulo = (1LL << 30) + 1;
const int INF = 2e9 + 1;
const double EPS = 1e-13;
int a[4][3];
bool better(pair<int, int> a, pair<int, int> b) {
  return a.first > b.second && a.second > b.first;
}
int main() {
  cin.sync_with_stdio(0);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++) cin >> a[i][j];
  pair<int, int> f1(a[0][0], a[1][1]), f2(a[1][0], a[0][1]);
  pair<int, int> s1(a[2][0], a[3][1]), s2(a[3][0], a[2][1]);
  if ((better(f1, s2) && better(f1, s1)) ||
      (better(f2, s2) && better(f2, s1))) {
    bool b[4] = {better(f1, s2), better(f1, s1), better(f2, s2),
                 better(f2, s1)};
    cout << "Team 1\n";
  } else if ((better(s1, f1) || better(s2, f1)) &&
             (better(s1, f2) || better(s2, f2)))
    cout << "Team 2\n";
  else
    cout << "Draw\n";
  return 0;
}
