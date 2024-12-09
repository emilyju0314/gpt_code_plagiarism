#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int q[100001];
int was[100001];
int w[100001];
int p[100001];
int in[100001];
int bad = 0;
int go(int x, int y) {
  p[x] = rand() & 1;
  q[y] = x;
  if (x == n / 2) {
    if (y != n - 1) return 0;
    for (int i = 0; i <= y; i++) printf("%d ", q[i]);
    printf("0\n");
    return 1;
  }
  was[x] = 1;
  int a = (2 * x + p[x]) % n;
  int b = (2 * x + 1 - p[x]) % n;
  in[a]--;
  in[b]--;
  int runs = 0;
  if (!was[a] && (in[b] || was[b])) {
    runs++;
    if (go(a, y + 1)) return 1;
  }
  if (!was[b] && (in[a] || was[a])) {
    runs++;
    bad -= runs == 2;
    if ((runs == 1 || bad > 0) && go(b, y + 1)) return 1;
  }
  was[x] = 0;
  in[a]++;
  in[b]++;
  return 0;
}
int main() {
  srand(3);
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) in[i] = 2;
  if (n & 1)
    printf("-1");
  else {
    do {
      bad = 15;
      if (go(0, 0)) return 0;
    } while (true);
  }
  return 0;
}
