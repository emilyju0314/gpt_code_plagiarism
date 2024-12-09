#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, m1, h2, m2;
  scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
  int t = (h2 - h1) * 60 + m2 - m1;
  t /= 2;
  printf("%02d:%02d", h1 + (m1 + t) / 60, (m1 + t) % 60);
  return 0;
}
