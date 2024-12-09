#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y;
long long a1[1005], a2[1005];
string s[1005];
void col() {
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '.')
        a1[j]++;
      else
        a2[j]++;
    }
  }
}
long long db[1005][1005][2];
long long solve(int i, int col, bool road) {
  if (col > y) return 1e12;
  if (i == m) {
    if (col < x) return 1e12;
    return 0;
  }
  long long& r = db[i][col][road];
  if (r != -1) return r;
  long long s1 = 1e12, s2 = 1e12, s3 = 1e12;
  if (col >= x && col <= y) {
    s3 = solve(i, 0, road);
  }
  if (col == 0) {
    if (road == 1) {
      s1 = a2[i] + solve(i + 1, col + 1, 0);
    } else {
      s1 = a1[i] + solve(i + 1, col + 1, 1);
    }
  } else {
    if (road == 1) {
      s1 = a1[i] + solve(i + 1, col + 1, road);
    } else {
      s1 = a2[i] + solve(i + 1, col + 1, road);
    }
  }
  return r = min(s3, min(s1, s2));
}
int main() {
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) cin >> s[i];
  col();
  memset(db, -1, sizeof(db));
  long long sul = min(solve(0, 0, 0), solve(0, 0, 1));
  cout << sul << endl;
  return 0;
}
