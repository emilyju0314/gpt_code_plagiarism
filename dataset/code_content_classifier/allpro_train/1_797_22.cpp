#include <bits/stdc++.h>
using namespace std;
long long b[35];
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n, i, ind = -1;
    cin >> n;
    long long ara[n + 1];
    for (i = 1; i <= n; i++) cin >> ara[i];
    for (i = 1; i <= n; i++) {
      long long x = ara[i];
      for (long long j = 1; j <= 32; j++) {
        if (x % 2 == 1) b[j]++;
        x /= 2;
      }
    }
    for (i = 32; i >= 1; i--) {
      if (b[i] % 2 == 1) {
        ind = i;
        break;
      }
    }
    if (ind == -1) {
      printf("DRAW\n");
      memset(b, 0, sizeof(b));
      continue;
    }
    if (n % 2 == 0) {
      printf("WIN\n");
    } else {
      if ((b[ind] / 2 + 1) % 2 == 1) {
        printf("WIN\n");
      } else {
        printf("LOSE\n");
      }
    }
    memset(b, 0, sizeof(b));
  }
}
