#include <bits/stdc++.h>
using namespace std;
const int Maxk = 10;
const int Maxn = (1 << 10);
const int Maxs = 75;
const long long inf = (long long)0x3f3f3f3f3f3f3f3f;
int S;
class mat {
 public:
  long long m[Maxs][Maxs];
  int r, c;
  mat(long long M[Maxs][Maxs] = {0}, int R = 0, int C = 0) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        m[i][j] = M[i][j];
      }
    }
    r = R;
    c = C;
  }
  mat operator*(const mat& o) const {
    long long tmp[Maxs][Maxs];
    memset(tmp, 0x3f, sizeof(tmp));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < o.c; j++) {
        for (int t = 0; t < c; t++) {
          if (m[i][t] < inf && o.m[t][j] < inf)
            tmp[i][j] = min(tmp[i][j], m[i][t] + o.m[t][j]);
        }
      }
    }
    return mat(tmp, r, o.c);
  }
  void print() {
    cout << "mat\n";
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (m[i][j] >= inf)
          cout << "inf ";
        else
          cout << m[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "mat\n";
  }
};
mat qpow(mat A, int B) {
  if (B == 1) return A;
  mat ret = qpow(A * A, B >> 1);
  if (B & 1) ret = ret * A;
  return ret;
}
int x, k, n, q;
int c[Maxk];
int state[Maxs], num = 0;
int id[Maxn];
unordered_map<int, int> val;
pair<int, int> stone[30];
mat A;
mat now;
int main() {
  scanf("%d%d%d%d", &x, &k, &n, &q);
  for (int i = 1; i <= k; i++) scanf("%d", c + i);
  val.clear();
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &stone[i].first, &stone[i].second);
    val[stone[i].first] = stone[i].second;
  }
  sort(stone + 1, stone + q + 1);
  S = 1;
  for (int i = k; i > k - x; i--) S *= i;
  for (int i = x; i > 0; i--) S /= i;
  for (int i = 0; i < (1 << k); i++) {
    int cnt = 0;
    for (int j = 0; j < k; j++) {
      if ((i >> j) & 1) cnt++;
    }
    if (cnt == x) {
      state[num] = i;
      id[i] = num++;
    }
  }
  long long tmp[Maxs][Maxs];
  memset(tmp, 0x3f, sizeof(tmp));
  for (int i = 0; i < S; i++) {
    int mask1, mask2;
    mask1 = state[i];
    if (mask1 & 1) {
      for (int d = 1; d <= k; d++) {
        if (((mask1 >> d) & 1) == 0) {
          mask2 = (mask1 | (1 << d)) >> 1;
          int j = id[mask2];
          tmp[j][i] = c[d];
        }
      }
    } else {
      mask2 = (mask1 >> 1);
      int j = id[mask2];
      tmp[j][i] = 0;
    }
  }
  A = mat(tmp, S, S);
  memset(tmp, 0x3f, sizeof(tmp));
  tmp[id[(1 << x) - 1]][0] = 0;
  now = mat(tmp, S, 1);
  int pos = 1, nex = 1;
  while (pos + x <= n) {
    if (nex > q) {
      mat mult = qpow(A, n + 1 - x - pos);
      now = mult * now;
      break;
    }
    if (stone[nex].first > n) stone[nex].first = n + 1;
    if (pos + k < stone[nex].first) {
      if (stone[nex].first > n + 1 + k - x) stone[nex].first = n + 1 + k - x;
      mat mult = qpow(A, stone[nex].first - k - pos);
      now = mult * now;
      pos = stone[nex].first - k;
    } else {
      while (pos < stone[nex].first && pos + x <= n) {
        memset(tmp, 0x3f, sizeof(tmp));
        for (int i = 0; i < S; i++) {
          int mask1, mask2;
          mask1 = state[i];
          if (mask1 & 1) {
            for (int d = 1; d <= k; d++) {
              if (((mask1 >> d) & 1) == 0) {
                mask2 = (mask1 | (1 << d)) >> 1;
                int j = id[mask2];
                tmp[j][i] = c[d];
                if (val.find(pos + d) != val.end()) tmp[j][i] += val[pos + d];
              }
            }
          } else {
            mask2 = (mask1 >> 1);
            int j = id[mask2];
            tmp[j][i] = 0;
          }
        }
        mat mult = mat(tmp, S, S);
        now = mult * now;
        pos++;
      }
      nex++;
    }
  }
  printf("%lld\n", now.m[id[(1 << x) - 1]][0]);
  return 0;
}
