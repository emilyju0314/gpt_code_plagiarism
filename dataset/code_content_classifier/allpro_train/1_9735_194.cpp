#include <bits/stdc++.h>
using namespace std;
string A, B;
int main() {
  int n;
  cin >> n;
  cin >> A >> B;
  int f, b, s, z;
  f = b = s = z = 0;
  for (int i = 0; i < A.size(); ++i)
    if (A[i] == '1' && B[i] == '1')
      ++b;
    else if (A[i] == '1')
      ++f;
    else if (B[i] == '1')
      ++s;
    else
      ++z;
  int ca = 0, cb = 0;
  n *= 2;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      if (b) {
        ++ca;
        --b;
      } else if (f) {
        ++ca;
        --f;
      } else if (s) {
        --s;
      } else
        --z;
    } else {
      if (b) {
        ++cb;
        --b;
      } else if (s) {
        --s;
        ++cb;
      } else if (f) {
        --f;
      } else
        --z;
    }
  }
  if (ca == cb)
    cout << "Draw";
  else if (ca > cb)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
