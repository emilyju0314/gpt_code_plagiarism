#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, p[3][1], p1, p2;
  p[0][0] = p[1][0] = p[2][0] = 0;
  string a, b;
  scanf("%d", &n);
  cin >> a >> b;
  c = a.size() * b.size();
  p1 = n / c;
  p2 = n % c;
  char j1, j2;
  for (int i = 0; i < c; i++) {
    j1 = a[i % a.size()];
    j2 = b[i % b.size()];
    if (j1 == 'R') {
      if (j2 == 'R')
        p[0][0]++;
      else if (j2 == 'P')
        p[1][0]++;
      else
        p[2][0]++;
    } else {
      if (j1 == 'P') {
        if (j2 == 'R')
          p[2][0]++;
        else if (j2 == 'P')
          p[0][0]++;
        else
          p[1][0]++;
      } else {
        if (j2 == 'R')
          p[1][0]++;
        else if (j2 == 'P')
          p[2][0]++;
        else
          p[0][0]++;
      }
    }
  }
  p[1][0] *= p1;
  p[2][0] *= p1;
  for (int i = 0; i < p2; i++) {
    j1 = a[i % a.size()];
    j2 = b[i % b.size()];
    if (j1 == 'R') {
      if (j2 == 'R')
        p[0][0]++;
      else if (j2 == 'P')
        p[1][0]++;
      else
        p[2][0]++;
    } else {
      if (j1 == 'P') {
        if (j2 == 'R')
          p[2][0]++;
        else if (j2 == 'P')
          p[0][0]++;
        else
          p[1][0]++;
      } else {
        if (j2 == 'R')
          p[1][0]++;
        else if (j2 == 'P')
          p[2][0]++;
        else
          p[0][0]++;
      }
    }
  }
  printf("%d %d\n", p[1][0], p[2][0]);
  return 0;
}
