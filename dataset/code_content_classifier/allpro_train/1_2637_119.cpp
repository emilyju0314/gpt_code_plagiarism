#include <bits/stdc++.h>
using namespace std;
int tu(int val) { return (1 << val); }
bool iset(int mask, int id) {
  if ((mask & tu(id)) != 0) return true;
  return false;
}
void doset(int &mask, int id) { mask |= tu(id); }
void dounset(int &mask, int id) { mask = mask & (~tu(id)); }
template <typename T>
string tos(T a) {
  stringstream ss;
  string ret;
  ss << a;
  ss >> ret;
  return ret;
}
const int LM = (1 << 19);
int AR[3 * LM], N;
inline void add(int pos, int val) {
  pos += LM - 1;
  AR[pos] += val;
  while (pos /= 2) AR[pos] = AR[pos + pos] + AR[pos + pos + 1];
}
inline int get(int l, int r, int L = 1, int R = LM, int v = 1) {
  if (r < L || l > R) return 0;
  if (l <= L && R <= r) return AR[v];
  const int mid = (L + R) / 2;
  return get(l, r, L, mid, v + v) + get(l, r, mid + 1, R, v + v + 1);
}
int main() {
  int q;
  while (cin >> N >> q) {
    memset(AR, 0, sizeof AR);
    ;
    int opt, oa, ob, l, r, lf, rt, dir;
    l = 1, r = N;
    dir = 1;
    for (int i = 1; i <= N; i++) add(i, 1);
    for (int(qq) = (0); (qq) < (q); (qq)++) {
      scanf("%d", &opt);
      if (opt == 1) {
        scanf("%d", &oa);
        int len = abs(l - r) + 1;
        lf = l + (dir * oa) - dir;
        rt = lf + dir;
        if (2 * oa <= len) {
          for (int(loop) = (0); (loop) < (oa); (loop)++) {
            int v = get(lf, lf);
            add(rt, v);
            lf -= dir;
            rt += dir;
          }
          l += oa * dir;
        } else {
          oa = len - oa;
          for (int(loop) = (0); (loop) < (oa); (loop)++) {
            int v = get(rt, rt);
            add(lf, v);
            lf -= dir;
            rt += dir;
          }
          r -= oa * dir;
          swap(l, r);
          dir *= -1;
        }
      } else {
        scanf("%d %d", &oa, &ob);
        ob--;
        int ra = l + oa * dir, rb = l + ob * dir;
        if (ra > rb) swap(ra, rb);
        printf("%d\n", get(ra, rb));
      }
    }
  }
  return 0;
}
