#include <bits/stdc++.h>
using namespace std;
void hehe() {
  int n, p, loop;
  cin >> n >> p;
  loop = (2 * n) + p;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (loop) {
        cout << i << " " << j << endl;
        loop--;
      }
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    hehe();
  }
  return 0;
}
