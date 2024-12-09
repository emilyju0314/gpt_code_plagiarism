#include <bits/stdc++.h>
using namespace std;

const double inf = 1e10;

double BMI(double w, double h) {
  return w / pow(h, 2);
}

int main() {
  int n;
  while(cin >> n && n) {
    pair<double,int> p(inf, 0);
    for(int i = 0; i < n; ++i) {
      int id;
      double h, w;
      cin >> id >> h >> w;
      h /= 100.0;
      p = min(p, make_pair(abs(22.0-BMI(w,h)), id));
    }
    cout << p.second << endl;
  }
  return 0;
}