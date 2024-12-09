#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  int sum = 0;
  char b[3] = {'R', 'G', 'B'};
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == a[i] && a[i] == a[i + 1]) {
      for (int j = 0; j < 3; j++) {
        if (b[j] != a[i]) {
          a[i] = b[j];
          break;
        }
      }
      sum++;
    } else if (a[i - 1] == a[i]) {
      for (int j = 0; j < 3; j++) {
        if (b[j] != a[i] && b[j] != a[i + 1]) {
          a[i] = b[j];
          break;
        }
      }
      sum++;
    }
  }
  printf("%d\n", sum);
  for (int i = 0; i < n; i++) {
    printf("%c", a[i]);
  }
}
