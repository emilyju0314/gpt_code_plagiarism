#include <bits/stdc++.h>
using namespace std;
int niz[1000];
int main() {
  int n;
  int br5 = 0;
  int br0 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &niz[i]);
    if (niz[i] == 0) br0++;
    if (niz[i] == 5) br5++;
  }
  int duzina = br5 / 9;
  if (duzina < 1) {
    if (br0 == 0)
      printf("-1");
    else
      printf("0");
  } else {
    if (br0 > 0) {
      for (int i = 1; i <= duzina * 9; i++) {
        printf("5");
      }
      for (int i = 1; i <= br0; i++) {
        printf("0");
      }
    } else
      printf("-1");
  }
  return 0;
}
