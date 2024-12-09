#include <bits/stdc++.h>
using namespace std;
pair<int, int> in(int val) {
  printf("? %d\n", val);
  fflush(stdout);
  int a, b;
  scanf("%d%d", &a, &b);
  return make_pair(a, b);
}
void out(int val) {
  printf("! %d\n", val);
  fflush(stdout);
  exit(0);
}
int main() {
  srand(time(0));
  int n, s, first;
  scanf("%d%d%d", &n, &s, &first);
  pair<int, int> best = in(s);
  if (best.first >= first) out(best.first);
  if (best.second == -1) out(-1);
  for (int i = (0), _for = (999); i < _for; ++i) {
    int cx = (rand() * rand() % n) + 1;
    pair<int, int> tmp = in(cx);
    if (tmp.first == first) out(first);
    if (tmp.first > best.first && tmp.first < first) best = tmp;
  }
  if (best.first >= first) out(best.first);
  if (best.second == -1) out(-1);
  for (int i = (0), _for = (999); i < _for; ++i) {
    s = best.second;
    best = in(s);
    if (best.first >= first) out(best.first);
    if (best.second == -1) out(-1);
  }
  out(-1);
  return 0;
}
