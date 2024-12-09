#include <bits/stdc++.h>
using namespace std;
const long long mm = 1e9 + 7;
vector<long long> vec[2], loop[2];
int now[2], sz[2], n, h, w;
char s[500500];
void go(char f, char b, int bound, int op) {
  int mxl = 0, mxr = 0, now = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (s[i] == f) {
      now++;
      if (now > mxr) mxr = now, vec[op].push_back(i);
    }
    if (s[i] == b) {
      now--;
      if (now < mxl) mxl = now, vec[op].push_back(i);
    }
  }
  for (int i = 0; i <= n - 1; i++) {
    if (s[i] == f) {
      now++;
      if (now > mxr) mxr = now, loop[op].push_back(i);
    }
    if (s[i] == b) {
      now--;
      if (now < mxl) mxl = now, loop[op].push_back(i);
    }
  }
  if (!loop[op].empty()) {
    while (vec[op].size() < bound) {
      for (int i = 0; i < (int)loop[op].size(); i++) loop[op][i] += n;
      for (auto x : loop[op]) vec[op].push_back(x);
    }
  }
  for (int i = 0; i < (int)vec[op].size(); i++) vec[op][i]++;
}
int main() {
  scanf("%d%d%d", &n, &h, &w);
  scanf("%s", s);
  go('R', 'L', w, 0);
  go('U', 'D', h, 1);
  long long ans = 0;
  sz[0] = vec[0].size();
  sz[1] = vec[1].size();
  while (now[0] < sz[0] || now[1] < sz[1]) {
    if (h == 0 || w == 0) break;
    if (now[1] == sz[1] ||
        (now[0] < sz[0] && vec[0][now[0]] < vec[1][now[1]])) {
      ans = (ans + 1ll * h * vec[0][now[0]] % mm) % mm;
      now[0]++;
      w--;
    } else {
      ans = (ans + 1ll * w * vec[1][now[1]] % mm) % mm;
      now[1]++;
      h--;
    }
  }
  if (h > 0 && w > 0) {
    puts("-1");
    return 0;
  }
  printf("%lld\n", ans);
  return 0;
}
