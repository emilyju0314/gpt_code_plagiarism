#include <bits/stdc++.h>
using namespace std;
int count(int b) {
  int count = 0;
  while (b) {
    count += (b & 1);
    b >>= 1;
  }
  return count;
}
bool check(int m[5][5], int b) {
  int lb = b & 0x1f;
  int vb = b >> 5;
  int co[6][6];
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      co[i][j] = 0;
    }
  }
  map<int, int> lm, vm;
  int c = 0;
  for (int i = 0; i < 5; ++i) {
    if (lb & (1 << i)) {
      lm[1 << i] = c;
      ++c;
    } else {
      lm[1 << i] = count(lb);
    }
  }
  c = 0;
  for (int i = 0; i < 5; ++i) {
    if (vb & (1 << i)) {
      vm[1 << i] = c;
      ++c;
    } else {
      vm[1 << i] = count(vb);
    }
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      co[lm[1 << i]][vm[1 << j]] += m[i][j];
    }
  }
  bool ok = true;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (co[i][j] > 1) {
        ok = false;
      }
    }
  }
  return ok;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
  int n;
  cin >> n;
  int m[5][5];
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      m[i][j] = 0;
    }
  }
  map<char, int> l;
  l['R'] = 0;
  l['G'] = 1;
  l['B'] = 2;
  l['Y'] = 3;
  l['W'] = 4;
  char a;
  int b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    m[l[a]][b - 1] = 1;
  }
  int mc = 10;
  for (int i = 0; i < (1 << 10); ++i) {
    if (check(m, i)) {
      mc = min(mc, count(i));
    }
  }
  cout << mc << "\n";
  return 0;
}
