#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, t1, t2;
  set<int> a;
  set<int> b, c;
  cin >> n >> p;
  int maxx = 1, minn = n;
  for (int i = 0; i < p; i++) {
    cin >> t1 >> t2;
    if (t1 > t2) swap(t1, t2);
    if (t1 > maxx) maxx = t1;
    if (t2 < minn) minn = t2;
    a.insert(t1);
    a.insert(t2);
  }
  if (maxx >= minn)
    cout << 0 << endl;
  else
    cout << minn - maxx << endl;
  return 0;
}
