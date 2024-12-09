#include <bits/stdc++.h>
using namespace std;
bool a[1000009];
int main() {
  int n;
  int s = 1000000;
  cin >> n;
  cout << n << endl;
  int i;
  for (i = (0); i < (n); ++i) {
    int x;
    scanf("%d", &x);
    a[x] = 1;
  }
  int p = 0;
  for (int i = 1; i <= s && n > 0; i++) {
    if (a[i] && (!a[s + 1 - i])) {
      cout << s + 1 - i << " ";
      n--;
      continue;
    }
  }
  for (int i = 1; i <= s && n > 0; i++) {
    if ((!a[i]) && (!a[s + 1 - i])) {
      cout << i << " " << s + 1 - i << " ";
      n = n - 2;
    }
  }
  return 0;
}
