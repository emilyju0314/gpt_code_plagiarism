#include <bits/stdc++.h>
using namespace std;
int main() {
  long lt[34], n, j, i;
  lt[0] = 1;
  cin >> n;
  for (int i = 1; i <= 30; i++) lt[i] = lt[i - 1] * 2;
  j = 30;
  while (n != 0) {
    for (i = j; i >= 0; i--)
      if (n >= lt[i]) {
        n -= lt[i];
        cout << i + 1 << ' ';
      }
    j = i;
  }
}
