#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int N = 3e5 + 4;
int n, len;
string a[3];
int ans[3], init[3], h[3], d[3];
void go(int i) {
  int now = init[i], add = min(n, len - now);
  if (!add) {
    ans[i] = (n == 1 ? now - 1 : now);
    return;
  }
  now += add;
  ans[i] = now;
}
void go2(int i) {
  int tmpn = n, add = min(len, tmpn);
  int curans = add;
  tmpn -= add;
  if (!tmpn) {
    d[i] = add;
    return;
  }
  int div = tmpn / len, mod = tmpn % len;
  if (div & 1) {
    curans = mod;
  } else {
    curans = (len - mod);
  }
  d[i] = curans;
}
void makeprefect() {
  for (int i = 0; i < 3; ++i) {
    h[i] = min(len - 1, init[i] + n);
  }
  for (int i = 0; i < 3; ++i) {
    go(i);
  }
  for (int i = 0; i < 3; ++i) {
    go2(i);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  len = a[0].size();
  int frq[150];
  for (int i = 0; i < 3; ++i) {
    memset(frq, 0, sizeof frq);
    for (int j = 0; j < (int)a[i].size(); ++j) {
      frq[a[i][j] - 'A']++;
    }
    int most = 0;
    for (int j = 0; j < 150; ++j) {
      most = max(most, frq[j]);
    }
    init[i] = most;
  }
  makeprefect();
  int Kuro = max(d[0], max(h[0], ans[0]));
  int Shiro = max(d[1], max(h[1], ans[1]));
  int Katie = max(d[2], max(h[2], ans[2]));
  if (Kuro > Shiro && Kuro > Katie)
    puts("Kuro");
  else if (Shiro > Kuro && Shiro > Katie)
    puts("Shiro");
  else if (Katie > Kuro && Katie > Shiro)
    puts("Katie");
  else
    puts("Draw");
}
