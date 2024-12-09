#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long x, s, j;
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &x);
    s = sqrt(x);
    for (j = 2; j * j < s; j++) {
      if (s % j == 0) break;
    }
    if (s * s == x && j * j > s && x != 1)
      printf("YES \n");
    else
      printf("NO \n");
  }
}
