#include <bits/stdc++.h>
using namespace std;
using namespace std;
void check() {
  int a, b, s = 0, k;
  cin >> a >> b;
  vector<int> v;
  for (typeof(a) i = 0; i < (a); ++i) {
    cin >> k;
    v.push_back(k);
  }
  for (typeof(a) i = 0; i < (a); ++i) {
    int c = v[i];
    for (typeof(3) j = 0; j < (3); ++j)
      if (c - b >= 0) c -= b;
    s += c;
  }
  cout << "\n" << s;
}
int main() {
  fstream ifile("input.txt");
  if (ifile) freopen("input.txt", "rt", stdin);
  if (ifile) freopen("output.txt", "wt", stdout);
  check();
  return 0;
}
