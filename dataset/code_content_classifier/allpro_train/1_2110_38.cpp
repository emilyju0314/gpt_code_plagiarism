#include <bits/stdc++.h>
using namespace std;
int a[1024];
int main() {
  int i, j, n, w, k, s, mn;
  cin >> n >> w;
  for (i = 0; i < n; ++i) cin >> a[i];
  if (n == 1) {
    if (a[0] != w) {
      cout << "No\n";
      return 0;
    } else {
      cout << "Yes\n";
      for (j = 0; j < a[0]; ++j) cout << "1 1 ";
      cout << '\n';
    }
  } else if (n >= 2) {
    if (w <= 0) {
      cout << "No\n";
      return 0;
    } else if (w == 1) {
      for (j = 0; j < n && a[j] != 1; ++j)
        ;
      if (j == n) {
        cout << "No\n";
        return 0;
      } else {
        cout << "Yes\n";
        a[j]--;
        cout << j + 1 << " ";
        for (i = 0; i < n; ++i)
          for (k = 0; k < a[i]; ++k) cout << i + 1 << " " << i + 1 << " ";
        cout << j + 1 << '\n';
      }
    } else if (w >= 2) {
      s = 0;
      mn = 10000;
      for (i = 0; i < n; ++i) {
        s += a[i];
        if (mn > a[i]) mn = a[i], k = i;
      }
      if (s < w) {
        cout << "No\n";
        return 0;
      } else {
        cout << "Yes\n";
        if (a[k] <= w) {
          cout << k + 1 << " ";
          s -= w;
          for (i = 0; i < n && s; ++i)
            if (i != k)
              while (a[i] && s) {
                cout << i + 1 << " " << i + 1 << " ";
                s--;
                a[i]--;
              }
          cout << k + 1 << " ";
          a[k]--;
          for (i = 0; i < n; ++i)
            for (k = 0; k < a[i]; ++k) cout << i + 1 << " " << i + 1 << " ";
          cout << "\n";
        } else {
          for (i = 0; i == k; ++i)
            ;
          cout << i + 1 << " ";
          j = k;
          mn = i;
          for (i = 0; i < n; ++i)
            if (i != j && i != mn)
              for (k = 0; k < a[i]; ++k) cout << i + 1 << " " << i + 1 << " ";
          for (i = 0; i < a[j] - w + 1; ++i)
            cout << j + 1 << " " << j + 1 << " ";
          cout << mn + 1 << " ";
          cout << j + 1 << " ";
          for (i = 1; i < a[mn]; ++i) cout << mn + 1 << " " << mn + 1 << " ";
          cout << j + 1 << " ";
          for (i = 2; i < w; ++i) cout << j + 1 << " " << j + 1 << " ";
          cout << '\n';
        }
      }
    } else
      while (true)
        ;
  } else
    while (true)
      ;
  return 0;
}
