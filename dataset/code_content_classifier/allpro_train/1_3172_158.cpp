#include <bits/stdc++.h>
using namespace std;
bool match(int a[], int b[], int n, bool t) {
  if (t)
    a[1] = 29;
  else
    a[1] = 28;
  for (int i = 0; i < 12; i++) {
    if (a[i] == b[0]) {
      bool f = 1;
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (n >= 12 && (i + j) % 12 == 1) {
          if (b[j] == 29 || b[j] == 28) {
            if (b[j] == 29) cnt++;
            if (b[j] == 28) cnt--;
            if (cnt == 2) {
              f = 0;
              break;
            }
            continue;
          }
        }
        if (a[(i + j) % 12] != b[j]) {
          f = 0;
          break;
        }
      }
      if (f) return 1;
    }
  }
  return 0;
}
int main() {
  int n;
  int a[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int b[30];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  if (match(a, b, n, 0) || match(a, b, n, 1))
    puts("Yes");
  else
    puts("No");
}
