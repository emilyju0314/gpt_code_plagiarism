#include <bits/stdc++.h>
using namespace std;
double binomial(int n, int a, int b) {
  int ret = 1, mx = max(a, b), mn = min(a, b);
  while (n > mx) {
    ret *= n;
    n--;
  }
  while (mn > 1) {
    ret /= mn;
    mn--;
  }
  return (double)ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int posReal = 0, negReal = 0, posRec = 0, negRec = 0, rem, remPos, remNeg;
  double prob;
  string real, rec;
  cout << fixed << setprecision(10);
  cin >> real;
  cin >> rec;
  for (int i = 0; i < (int)real.length(); i++) {
    if (real[i] == '+')
      posReal++;
    else
      negReal++;
  }
  for (int i = 0; i < (int)rec.length(); i++) {
    if (rec[i] == '+')
      posRec++;
    else if (rec[i] == '-')
      negRec++;
  }
  rem = (posReal + negReal) - (posRec + negRec);
  if (rem == 0) {
    if (posRec == posReal && negRec == negReal)
      prob = 1;
    else
      prob = 0;
  } else if (posRec > posReal || negRec > negReal) {
    prob = 0;
  } else {
    remPos = posReal - posRec;
    remNeg = negReal - negRec;
    prob = ((double)((double)1) / ((double)(1 << rem))) *
           binomial(rem, remPos, remNeg);
  }
  cout << prob << "\n";
  return 0;
}
