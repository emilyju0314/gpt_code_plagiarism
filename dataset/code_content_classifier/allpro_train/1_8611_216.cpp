#include <bits/stdc++.h>
using namespace std;
int tu(int val) { return (1 << val); }
bool iset(int mask, int id) {
  if ((mask & tu(id)) != 0) return true;
  return false;
}
void doset(int &mask, int id) { mask |= tu(id); }
void dounset(int &mask, int id) { mask = mask & (~tu(id)); }
template <typename T>
string tos(T a) {
  stringstream ss;
  string ret;
  ss << a;
  ss >> ret;
  return ret;
}
int hpm, atkm, defm;
int lagbe(int hpy, int atky, int defy) {
  int wm = max(0, atky - defm);
  int wy = max(0, atkm - defy);
  if (wm == 0) return -1;
  if (wy == 0) return 0;
  int chpm = hpm;
  while (true) {
    if (chpm <= 0) {
      if (hpy > 0)
        return 0;
      else
        return (-hpy) + 1;
    }
    chpm -= wm;
    hpy -= wy;
  }
}
int main() {
  int hpy, atky, defy;
  int hp, atk, def;
  while (cin >> hpy >> atky >> defy) {
    cin >> hpm >> atkm >> defm;
    cin >> hp >> atk >> def;
    int res = 1 << 29;
    for (int(i) = (0); (i) < (300); (i)++)
      for (int(j) = (0); (j) < (300); (j)++) {
        int ra = lagbe(hpy, atky + i, defy + j);
        if (ra == -1) continue;
        res = min(res, ra * hp + i * atk + j * def);
      }
    cout << res << endl;
  }
  return 0;
}
