#include <bits/stdc++.h>
using namespace std;
int main() {
  int check = 0, n, i, j, count = 0, now = 0, x;
  cin >> n;
  vector<int> v;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  for (i = 0; i < n; i++) {
    now = 0;
    if (v[i] != 0) {
      for (j = i + 1; j < n; j++) {
        if (v[i] == v[j]) now++;
      }
      now++;
      if (now > 2) {
        check = 1;
        break;
      } else if (now == 2)
        count++;
    }
    if (check == 1) {
      break;
    }
  }
  if (check == 1)
    cout << -1;
  else
    cout << count;
  return 0;
}
