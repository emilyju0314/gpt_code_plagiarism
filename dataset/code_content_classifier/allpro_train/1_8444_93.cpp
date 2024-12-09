#include <bits/stdc++.h>
using namespace std;
unsigned long long t, w, b, minn, minc, s, tong;
unsigned long long ucln(unsigned long long a, unsigned long long b) {
  unsigned long long sa = max(a, b), sb = min(a, b);
  while (sb != 0) {
    unsigned long long ccc = sb;
    sb = sa % sb;
    sa = ccc;
  }
  return sa;
}
unsigned long long cnv(unsigned long long &a) {
  unsigned long long dem = 0;
  while (a > 9) {
    dem++;
    a /= 10;
  }
  dem++;
  return dem;
}
int main() {
  cin >> t >> w >> b;
  if (w == b) {
    cout << "1/1";
    return 0;
  }
  minn = min(w, b) - 1;
  if (w > b)
    w = w / (ucln(w, b));
  else
    b = b / (ucln(w, b));
  if (w < b) {
    unsigned long long tg = w;
    w = b;
    b = tg;
  }
  unsigned long long ww = w, bb = b, demw = 0, demb = 0, tt = t, demt = 0, vler;
  demw = cnv(ww);
  demb = cnv(bb);
  demt = cnv(tt);
  if (demb + demw > demt + 1) {
    vler = t + 1;
    s = 0;
  } else {
    vler = w * b;
    s = t / vler;
  }
  tong = minn * s + min(minn, t % vler) + s;
  unsigned long long nnn;
  nnn = ucln(tong, t);
  cout << tong / nnn << "/" << t / nnn;
}
