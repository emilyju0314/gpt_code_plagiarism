#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int maxHP, reg, HP, turns;
struct scroll {
  int power;
  int dam;
  int num;
  void read(int id) {
    num = id;
    scanf("%d%d", &power, &dam);
  }
  int can() { return (100 * HP <= power * maxHP); }
};
int n;
scroll a[1 << 11];
int used[1 << 11];
void init() {
  scanf("%d%d%d", &n, &maxHP, &reg);
  HP = maxHP;
  for (int i = 0; i < n; ++i) a[i].read(i + 1);
}
void ans(int x) {
  if (x == -1) {
    puts("NO");
    exit(0);
  }
  puts("YES");
  printf("%d %d\n", turns, x);
  for (int i = 0; i < x; ++i) {
    printf("%d %d\n", used[i], a[i].num);
  }
  exit(0);
}
int main() {
  init();
  int sumDam = 0;
  int X = 0;
  turns = 0;
  while (true) {
    HP -= sumDam;
    HP += reg;
    HP = min(HP, maxHP);
    if (HP <= 0) break;
    if (X < n) {
      for (int i = X + 1; i < n; ++i) {
        if (!a[i].can()) continue;
        if (!a[X].can()) swap(a[i], a[X]);
        if (!a[i].can()) continue;
        if (a[i].dam > a[X].dam) swap(a[i], a[X]);
      }
    }
    if ((X == n || !a[X].can()) && sumDam <= reg) ans(-1);
    if (X < n && a[X].can()) {
      used[X] = turns;
      sumDam += a[X].dam;
      ++X;
    }
    ++turns;
  }
  ans(X);
  return 0;
}
