#include <bits/stdc++.h>
using namespace std;
template <int n>
using AI = array<int, n>;
const double eps = 1e-9;
const int oo = 0x3F3F3F3F;
const long long ooLL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1000000007;
template <typename T>
T sqr(T x) {
  return x * x;
}
const double PI = acos(-1.);
long long Round(double x) { return x < 0 ? x - .5 : x + .5; }
int main() {
  void run();
  run();
  return 0;
}
int n;
char s[1 << 20];
void run() {
  scanf("%d\n%s", &n, s);
  while (1) {
    vector<string> t;
    string p = s;
    for (int it = (0), _b(3); it < _b; ++it) {
      string c;
      int w = 0;
      vector<int> pr = {20, 10, 0};
      for (int i = 0; i < p.size();) {
        if (c.size()) c += '+';
        int a = 0;
        for (int j = -1, jj = i + 1 < p.size() && rand() % 100 < pr[it]; j < jj;
             ++j, ++i) {
          c += p[i];
          a = a * 10 + p[i] - '0';
        }
        w += a;
      }
      t.push_back(c);
      p = to_string(w);
    }
    if (p.size() == 1) {
      for (auto &z : t) puts(z.c_str());
      break;
    }
  }
}
