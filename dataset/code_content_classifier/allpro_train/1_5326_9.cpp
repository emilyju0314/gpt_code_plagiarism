#include <bits/stdc++.h>
using namespace std;
struct vet {
  int x, y;
  int id;
  vet operator-(vet a) {
    vet aux;
    aux.x = x - a.x;
    aux.y = y - a.y;
    return aux;
  }
  int quadrante() const {
    if (x >= 0 && y >= 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x <= 0 && y <= 0) return 3;
    if (x > 0 && y < 0) return 4;
  }
  int cross(vet a) const { return (x * a.y) - (y * a.x); }
  int dot(vet a) const { return (x * a.x) + (y * a.y); }
  int mod() const { return dot(*this); }
  bool operator<(vet a) const {
    if (quadrante() != a.quadrante()) {
      return quadrante() < a.quadrante();
    }
    if (cross(a) == 0) {
      return dot(*this) < a.dot(a);
    }
    return cross(a) > 0;
  }
  long double ang(vet a) {
    long double ans = atan2(cross(a), dot(a));
    if (ans < 0) ans += 2 * acos(-1);
    return ans;
  }
} vetores[112345];
int n, ansi, ansj;
long double ans1 = 1e9;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &vetores[i].x, &vetores[i].y);
    vetores[i].id = i;
  }
  sort(vetores, vetores + n);
  for (int i = 1; i < n; i++) {
    if (vetores[i - 1].ang(vetores[i]) < ans1) {
      ansi = vetores[i - 1].id;
      ansj = vetores[i].id;
      ans1 = vetores[i - 1].ang(vetores[i]);
    }
  }
  if (vetores[n - 1].ang(vetores[0]) < ans1) {
    ansi = vetores[n - 1].id;
    ansj = vetores[0].id;
  }
  printf("%d %d\n", ansi + 1, ansj + 1);
}
