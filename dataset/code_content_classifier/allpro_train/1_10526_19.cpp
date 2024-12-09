#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void sync_stdio() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
int intersect(pair<int, int> a, pair<int, int> b) {
  return !(b.second <= a.first || a.second <= b.first);
}
int main() {
  int a, ta, b, tb;
  scanf("%d%d%d%d", &a, &ta, &b, &tb);
  int h, m;
  scanf("%d:%d", &h, &m);
  int tm = h * 60 + m;
  int START = 5 * 60;
  int END = 24 * 60;
  int res = 0;
  for (int i = START; i < END; i += b) {
    if (intersect({tm, tm + ta}, {i, i + tb})) {
      ++res;
    }
  }
  printf("%d", res);
  return 0;
}
