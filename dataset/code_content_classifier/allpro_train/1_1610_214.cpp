#include <bits/stdc++.h>
using namespace std;
int infinito = 1000000001;
const int primero = 1 << 10;
const int tope = 1 << 11;
int minimo[tope];
void inserta(int pos, int val) {
  pos += primero;
  minimo[pos] = val;
  while (pos > 1) {
    pos >>= 1;
    minimo[pos] = min(minimo[pos << 1], minimo[(pos << 1) | 1]);
  }
}
int minimapos() {
  int pos = 1;
  while (pos < primero) {
    if (minimo[pos << 1] < minimo[(pos << 1) | 1])
      pos <<= 1;
    else
      pos = (pos << 1) | 1;
  }
  return pos - primero;
}
int n, m;
int a[tope];
int rechazados(long long int s) {
  for (int i = 1; i < tope; i++) minimo[i] = infinito;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    int ai = a[i];
    if (s + ai >= 0) {
      inserta(i, ai);
      s += ai;
    } else {
      c++;
      int pos = minimapos();
      int apos = minimo[pos + primero];
      if (apos < ai) {
        s += ai - apos;
        inserta(pos, ai);
      }
    }
  }
  return c;
}
long long int computa(int r) {
  long long int inf = -1LL;
  long long int sup = 750000000001LL;
  while (inf + 1 < sup) {
    long long int med = (inf + sup) / 2;
    if (rechazados(med) < r)
      sup = med;
    else
      inf = med;
  }
  return sup;
}
long long int valorconmenosque[751];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &(a[i]));
  for (int r = 1; r < 751; r++) valorconmenosque[r] = computa(r);
  for (int i = 1; i <= m; i++) {
    long long int b;
    scanf("%lld", &b);
    int rinf = 0;
    int rsup = 751;
    while (rinf + 1 < rsup) {
      int rmed = (rinf + rsup) / 2;
      if (b >= valorconmenosque[rmed])
        rsup = rmed;
      else
        rinf = rmed;
    }
    printf("%d\n", rinf);
  }
}
