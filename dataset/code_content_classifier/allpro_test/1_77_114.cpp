#include <bits/stdc++.h>
using namespace std;
long long ara[1000][1000];
vector<long long> v;
long long room(long long f, long long i, long long j) {
  if (ara[i][j] == -1) {
    return 0;
  }
  char bin[5] = "0000";
  long long c, d, k = 3, l, x = 0;
  c = ara[i][j];
  do {
    bin[k] = (c % 2) + '0';
    c /= 2;
    k--;
  } while (c != 0);
  if (f != -1) {
    if (bin[f] == '1') {
      ara[i][j] = -1;
      return 0;
    }
  }
  ara[i][j] = -1;
  for (k = 0; k < 4; k++) {
    if (k != f) {
      if (bin[k] == '0') {
        if (k == 0) {
          x += room(2, i - 1, j);
        } else if (k == 1) {
          x += room(3, i, j + 1);
        } else if ((k == 2)) {
          x += room(0, i + 1, j);
        } else if ((k == 3)) {
          x += room(1, i, j - 1);
        }
      }
    }
  }
  return x + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, i, j, c, d, s = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> ara[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ara[i][j] != -1) {
        v.push_back(room(-1, i, j));
      }
    }
  }
  sort(v.begin(), v.end(), greater<long long>());
  d = v.size();
  for (i = 0; i < d; i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
  return 0;
}
