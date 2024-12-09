#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
long long int x;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    x += a[i];
  }
  if (x & 1) {
    cout << "NO" << endl;
    return 0;
  }
  set<long long int> ase;
  long long int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    if (cur == x / 2) {
      cout << "YES" << endl;
      return 0;
    }
    if (cur > x / 2 && ase.find(cur - x / 2) != ase.end()) {
      cout << "YES" << endl;
      return 0;
    }
    ase.insert(a[i]);
  }
  reverse(a, a + n);
  ase.clear();
  cur = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    if (cur == x / 2) {
      cout << "YES" << endl;
      return 0;
    }
    if (cur > x / 2 && ase.find(cur - x / 2) != ase.end()) {
      cout << "YES" << endl;
      return 0;
    }
    ase.insert(a[i]);
  }
  cout << "NO" << endl;
}
