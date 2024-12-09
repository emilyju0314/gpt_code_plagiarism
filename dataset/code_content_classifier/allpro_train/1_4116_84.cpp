#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], b[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int s1 = -1, s2 = -1;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      s1 = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == a[s1]) {
      s2 = i;
      break;
    }
  }
  bool ok = true;
  while (s1 < n) {
    if (a[s1] == b[s2]) {
      s1++;
      s2 = (s2 + 1) % n;
    } else if (!a[s1]) {
      s1++;
    } else if (!b[s2]) {
      s2 = (s2 + 1) % n;
    } else {
      ok = false;
      break;
    }
  }
  if (ok)
    puts("YES");
  else
    puts("NO");
  return 0;
}
