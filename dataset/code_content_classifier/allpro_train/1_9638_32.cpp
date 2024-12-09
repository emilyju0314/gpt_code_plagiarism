#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1E-7;
const int oo = 123456789;
int a[3];
vector<int> v;
int k;
int hzz() {
  for (int w = 0; w <= 20; w++) {
    int tmp = 0;
    for (int i = 0; i < v.size(); i++)
      if (v[i] & (1 << w)) tmp++;
    if (tmp % (k + 1)) return 1;
  }
  return 0;
}
int main() {
  int n, m;
  string s;
  cin >> n >> m >> k;
  memset((a), 0, sizeof((a)));
  for (int(r) = 0; (r) < (n); ++(r)) {
    cin >> s;
    int z1 = -1, z2 = -1, have = 0;
    for (int(i) = 0; (i) < (s.size()); ++(i)) {
      if (s[i] == 'G') z1 = i;
      if (s[i] == 'R') z2 = i;
      if (s[i] == '-') have = 1;
    }
    if (z1 >= 0 && z2 >= 0) {
      v.push_back(abs(z1 - z2) - 1);
    } else if (z1 >= 0) {
      if (have) a[1]++;
    } else if (z2 >= 0) {
      if (have) a[2]++;
    }
  }
  int win1 = hzz();
  if (a[1] && a[2]) {
    puts("Draw");
  } else if (a[1]) {
    puts("First");
  } else if (a[2]) {
    puts("Second");
  } else {
    if (win1)
      puts("First");
    else
      puts("Second");
  }
  return 0;
}
