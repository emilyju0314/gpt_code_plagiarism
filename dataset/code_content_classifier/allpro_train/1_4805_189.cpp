#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int flag[1000005], prime[1000005], count1;
void getprime(int n) {
  int i, j;
  memset(flag, 0, sizeof(flag));
  flag[1] = 1;
  flag[0] = 1;
  for (i = 2; i <= n; i++) {
    if (flag[i] == 0) prime[++count1] = i;
    for (j = 1; j <= count1 && i * prime[j] <= n; j++) {
      flag[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
bool isprime(int x) {
  if (x <= 1000000) {
    return 1 ^ flag[x];
  } else {
    for (int i = 1; i <= count1 && 1LL * prime[i] * prime[i] <= 1LL * x; i++) {
      if (x % prime[i] == 0) return 0;
    }
    return 1;
  }
}
int main() {
  getprime(1000000);
  int i, j, m, n, t;
  scanf("%d", &n);
  if (n < 9) {
    printf("%d\n%d\n", 1, n);
  } else {
    printf("3\n3");
    n -= 3;
    for (i = 1; i <= count1; i++) {
      if (isprime(n - prime[i])) {
        printf(" %d %d\n", prime[i], n - prime[i]);
        break;
      }
    }
  }
  return 0;
}
