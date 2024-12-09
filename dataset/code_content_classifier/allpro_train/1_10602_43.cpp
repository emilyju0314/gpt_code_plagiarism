#include <bits/stdc++.h>
using namespace std;
int n, p, k;
void solve() {
  int i, trai, phai;
  trai = p - k;
  if (trai < 1) trai = 1;
  phai = p + k;
  if (phai > n) phai = n;
  if (trai > 1) cout << "<< ";
  for (i = trai; i <= phai; i++) {
    if (i > trai) cout << " ";
    if (i == p)
      cout << "(" << i << ")";
    else
      cout << i;
  }
  if (phai < n) cout << " >>";
  cout << endl;
}
void input() {
  int i;
  while (cin >> n >> p >> k) {
    solve();
  }
}
int main() {
  input();
  return 0;
}
