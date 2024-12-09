#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int an = a.length(), bn = b.length();
  vector<int> c(an + 1);
  for (int i = 0; i < an; i++) c[i + 1] = c[i] + (a[i] == '1');
  long long v = 0;
  for (int i = 0; i < bn; i++) {
    int j1 = max(0, an - (bn - i));
    int j2 = min(an - 1, i);
    int c1 = c[j2 + 1] - c[j1];
    v += b[i] == '0' ? c1 : j2 + 1 - j1 - c1;
  }
  cout << v << '\n';
}
