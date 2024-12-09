#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  int a, b;
  scanf("%d %d %d", &n, &a, &b);
  int ans = 0;
  int minim = min(a, b);
  int maks = max(a, b);
  int jumlah1 = 4, jumlah2 = 2;
  int panjang = n;
  vector<int> listSisaPanjang;
  int cnt = 0;
  if ((4 * a + 2 * b) <= panjang) {
    printf("1\n");
    return 0;
  }
  if (b > a && (b + a + a) <= n) {
    printf("2\n");
    return 0;
  }
  if (a > b) {
    while (jumlah1 > 0) {
      panjang = n;
      if (panjang >= a) {
        cnt++;
      }
      while (panjang >= a) {
        panjang -= a;
        jumlah1--;
        if (jumlah1 == 0) {
          break;
        }
      }
      if (jumlah1 > 0) {
        listSisaPanjang.push_back(panjang);
      }
    }
    listSisaPanjang.push_back(panjang);
    for (i = 0; i < listSisaPanjang.size(); i++) {
      int pjg = listSisaPanjang[i];
      while (pjg >= b) {
        pjg -= b;
        jumlah2--;
        if (jumlah2 == 0) {
          break;
        }
      }
      if (jumlah2 == 0) {
        break;
      }
    }
    while (jumlah2 > 0) {
      panjang = n;
      if (panjang >= b) {
        cnt++;
      }
      while (panjang >= b) {
        panjang -= b;
        jumlah2--;
        if (jumlah2 == 0) {
          break;
        }
      }
    }
    printf("%d\n", cnt);
  } else {
    while (jumlah2 > 0) {
      panjang = n;
      if (panjang >= b) {
        cnt++;
      }
      while (panjang >= b) {
        panjang -= b;
        jumlah2--;
        if (jumlah2 == 0) {
          break;
        }
      }
      if (jumlah2 > 0) {
        listSisaPanjang.push_back(panjang);
      }
    }
    listSisaPanjang.push_back(panjang);
    for (i = 0; i < listSisaPanjang.size(); i++) {
      int pjg = listSisaPanjang[i];
      while (pjg >= a) {
        pjg -= a;
        jumlah1--;
        if (jumlah1 == 0) {
          break;
        }
      }
      if (jumlah1 == 0) {
        break;
      }
    }
    while (jumlah1 > 0) {
      panjang = n;
      if (panjang >= a) {
        cnt++;
      }
      while (panjang >= a) {
        panjang -= a;
        jumlah1--;
        if (jumlah1 == 0) {
          break;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
};
