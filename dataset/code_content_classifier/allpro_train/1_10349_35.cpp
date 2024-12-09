#include <bits/stdc++.h>
using namespace std;
int mas[5000001], bgg[5000001], primes[5000001], primescount = 2;
inline int isprime(int num) {
  int i;
  if (num == 4999995) {
    i = 1000;
  }
  for (i = 0; (i < primescount) && (num >= primes[i] * primes[i]); i++) {
    if (num % (primes[i]) == 0) return primes[i];
  }
  return 0;
}
int main() {
  mas[1] = 1;
  mas[2] = 1;
  mas[3] = 1;
  int i;
  primes[0] = 2;
  primes[1] = 3;
  bgg[1] = 1;
  bgg[2] = 2;
  bgg[3] = 3;
  for (i = 4; i <= 5000000; i++) {
    if (i % 2 == 0) {
      mas[i] = 1 + mas[i / 2];
      bgg[i] = bgg[i - 1] + mas[i];
    } else {
      int ipr = isprime(i);
      if (ipr == 0) {
        mas[i] = 1;
        primes[primescount] = i;
        primescount++;
      } else {
        mas[i] = 1 + mas[i / ipr];
      }
      bgg[i] = bgg[i - 1] + mas[i];
    }
  }
  int n;
  cin >> n;
  int a, b;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", bgg[a] - bgg[b]);
  }
  return 0;
}
