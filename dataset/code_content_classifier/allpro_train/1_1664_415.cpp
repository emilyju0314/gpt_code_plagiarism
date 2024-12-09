#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double pi = 2 * acos(0.0);
long long a1, a2, a3, b1, b2, b3, c, c1, c2, c3, d, d1, d2, d3, d4, d5, e1, e2,
    e3, f, h, k, l, m, n, m1, m2, n1, n2, o, p, p1, p2, p3, p4, q, q1, q2, q3,
    q4, r, s, t, u, v, x, y, z, sum, mx = -1e15, mn = 1e15, flg, flg1, flg2,
                                     id1, id2, id3, id4, lim, mx_id;
char str1[200001], str2[200001];
vector<long long> V;
void solve() {
  c = 0;
  flg = 0;
  id1 = 0;
  id2 = n - 1;
  V.clear();
  for (long long i = n - 1; i >= 0; i--) {
    if (flg) {
      if (str1[id1] == str2[i]) {
        if (str1[id2] != str2[i]) {
          V.push_back(1);
          c++;
        }
        V.push_back(i + 1);
        c++;
        flg = flg ^ 1;
        id2--;
      } else {
        id1++;
      }
    } else {
      if (str1[id2] != str2[i]) {
        if (str1[id1] == str2[i]) {
          V.push_back(1);
          c++;
        }
        V.push_back(i + 1);
        c++;
        flg = flg ^ 1;
        id1++;
      } else {
        id2--;
      }
    }
  }
  printf("%I64d ", c);
  for (long long i = 0; i < c; i++) printf("%I64d ", V[i]);
  printf("\n");
}
int main() {
  t = 1;
  scanf("%I64d", &t);
  while (t--) {
    scanf("%I64d", &n);
    scanf("%s%s", str1, str2);
    solve();
  }
  return 0;
}
