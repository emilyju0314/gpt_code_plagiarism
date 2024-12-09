#include <bits/stdc++.h>
using namespace std;
void ask(int a, int b) {
  printf("? %i %i\n", a, b);
  fflush(stdout);
}
int read(void) {
  int x;
  scanf("%i", &x);
  return x;
}
int main(void) {
  int n;
  scanf("%i", &n);
  vector<int> xors(n);
  for (int i = 0; i < n; i++) {
    ask(i, i);
    xors[i] = read();
  }
  vector<int> cross(n);
  for (int i = 0; i < n; i++) {
    ask(0, i);
    cross[i] = read();
  }
  for (int i = 0; i < n; i++) {
    if (cross[i]) {
      continue;
    }
    vector<int> cands;
    for (int j = 0; j < n; j++) {
      if (xors[j] == i) {
        cands.push_back(j);
      }
    }
    int ans = 0;
    vector<int> sol;
    for (int e : cands) {
      vector<int> p(n), q(n);
      for (int j = 0; j < n; j++) {
        p[j] = cross[j] ^ e;
        q[j] = p[j] ^ xors[j];
      }
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (p[q[j]] != j) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans++;
        if (ans == 1) {
          sol = q;
        }
      }
    }
    puts("!");
    printf("%i\n", ans);
    for (int j = 0; j < n; j++) {
      printf("%i ", sol[j]);
    }
    puts("");
    fflush(stdout);
  }
  return 0;
}
