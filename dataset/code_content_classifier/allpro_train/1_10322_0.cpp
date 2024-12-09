#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
inline long long int pwm(long long int xx, long long int pow,
                         long long int MD) {
  if (pow < 0) {
    pow = pow % (MD - 1) + MD - 1;
  }
  long long int mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      mlt %= MD;
    }
    xx *= xx;
    pow >>= 1;
    xx %= MD;
  }
  return mlt;
}
inline long long int gcdex(long long int a, long long int b, long long int &x,
                           long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int xx, yy;
  long long int gc = gcdex(b, a % b, yy, xx);
  x = xx;
  y = yy - (a / b) * xx;
  return gc;
}
inline int inv(long long int r, int _mod) {
  return pwm(r % _mod, _mod - 2, _mod);
}
inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow - 1);
  int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
  int64_t ans = seg * subSquareSize;
  int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}
struct tup {
  int predper, per;
};
int grandi[1000][3];
tup per[6][6][6];
vector<long long int> arr;
int x, y, z;
int mex(vector<int> kek) {
  for (int i = 0; i <= 4; i++) {
    bool ok = false;
    for (int son : kek) {
      if (son == i) ok = true;
    }
    if (!ok) return i;
  }
}
void precalc() {
  for (x = 1; x < 6; x++) {
    for (y = 1; y < 6; y++) {
      for (z = 1; z < 6; z++) {
        for (int i = 1; i < 1000; i++) {
          grandi[i][0] =
              mex({grandi[max(i - x, 0)][0], grandi[max(i - y, 0)][1],
                   grandi[max(i - z, 0)][2]});
          grandi[i][1] =
              mex({grandi[max(i - x, 0)][0], grandi[max(i - z, 0)][2]});
          grandi[i][2] =
              mex({grandi[max(i - x, 0)][0], grandi[max(i - y, 0)][1]});
        }
        for (int i = 0; i < 1000; i++) {
          bool kekk = false;
          for (int j = i + 1; j < 1000 - 6; j++) {
            bool ok = true;
            for (int s = 0; s < 6; s++) {
              for (int h = 0; h < 3; h++) {
                if (grandi[i + s][h] != grandi[j + s][h]) ok = false;
              }
            }
            if (ok) {
              per[x][y][z] = {i, j - i};
              kekk = true;
              break;
            }
          }
          if (kekk) break;
        }
      }
    }
  }
  for (x = 1; x < 6; x++) {
    for (y = 1; y < 6; y++) {
      for (z = 1; z < 6; z++) {
      }
    }
  }
}
int getgrandi(long long int n, int laststep) {
  if (n < 40) {
    return grandi[n][laststep];
  }
  return grandi[(n - per[x][y][z].predper) % per[x][y][z].per +
                per[x][y][z].predper][laststep];
}
int zaebalsya[3];
void solve() {
  int n;
  cin >> n;
  cin >> x >> y >> z;
  zaebalsya[0] = x;
  zaebalsya[1] = y;
  zaebalsya[2] = z;
  arr.resize(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 1; i < 40; i++) {
    grandi[i][0] = mex({grandi[max(i - x, 0)][0], grandi[max(i - y, 0)][1],
                        grandi[max(i - z, 0)][2]});
    grandi[i][1] = mex({grandi[max(i - x, 0)][0], grandi[max(i - z, 0)][2]});
    grandi[i][2] = mex({grandi[max(i - x, 0)][0], grandi[max(i - y, 0)][1]});
  }
  int ans = 0;
  int allxor = 0;
  for (int i = 0; i < n; i++) {
    allxor ^= getgrandi(arr[i], 0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int res = allxor;
      res ^= getgrandi(arr[i], 0);
      res ^= getgrandi(max(arr[i] - zaebalsya[j], (long long int)0), j);
      ans += (res == 0);
    }
  }
  cout << ans << endl;
}
void shit() {
  per[1][1][1] = {0, 2};
  per[1][1][2] = {0, 3};
  per[1][1][3] = {0, 4};
  per[1][1][4] = {0, 5};
  per[1][1][5] = {0, 6};
  per[1][2][1] = {0, 3};
  per[1][2][2] = {0, 3};
  per[1][2][3] = {8, 4};
  per[1][2][4] = {10, 5};
  per[1][2][5] = {0, 6};
  per[1][3][1] = {0, 4};
  per[1][3][2] = {8, 4};
  per[1][3][3] = {3, 2};
  per[1][3][4] = {12, 7};
  per[1][3][5] = {11, 2};
  per[1][4][1] = {0, 5};
  per[1][4][2] = {10, 5};
  per[1][4][3] = {12, 7};
  per[1][4][4] = {3, 5};
  per[1][4][5] = {26, 3};
  per[1][5][1] = {0, 6};
  per[1][5][2] = {0, 6};
  per[1][5][3] = {11, 2};
  per[1][5][4] = {26, 3};
  per[1][5][5] = {5, 2};
  per[2][1][1] = {0, 3};
  per[2][1][2] = {5, 3};
  per[2][1][3] = {8, 4};
  per[2][1][4] = {7, 5};
  per[2][1][5] = {11, 6};
  per[2][2][1] = {5, 3};
  per[2][2][2] = {0, 4};
  per[2][2][3] = {0, 5};
  per[2][2][4] = {0, 6};
  per[2][2][5] = {0, 7};
  per[2][3][1] = {8, 4};
  per[2][3][2] = {0, 5};
  per[2][3][3] = {0, 5};
  per[2][3][4] = {0, 6};
  per[2][3][5] = {12, 7};
  per[2][4][1] = {7, 5};
  per[2][4][2] = {0, 6};
  per[2][4][3] = {0, 6};
  per[2][4][4] = {0, 6};
  per[2][4][5] = {20, 7};
  per[2][5][1] = {11, 6};
  per[2][5][2] = {0, 7};
  per[2][5][3] = {12, 7};
  per[2][5][4] = {20, 7};
  per[2][5][5] = {4, 7};
  per[3][1][1] = {3, 2};
  per[3][1][2] = {8, 4};
  per[3][1][3] = {10, 4};
  per[3][1][4] = {13, 5};
  per[3][1][5] = {9, 6};
  per[3][2][1] = {8, 4};
  per[3][2][2] = {0, 5};
  per[3][2][3] = {7, 5};
  per[3][2][4] = {11, 6};
  per[3][2][5] = {12, 7};
  per[3][3][1] = {10, 4};
  per[3][3][2] = {7, 5};
  per[3][3][3] = {0, 6};
  per[3][3][4] = {0, 7};
  per[3][3][5] = {0, 8};
  per[3][4][1] = {13, 5};
  per[3][4][2] = {11, 6};
  per[3][4][3] = {0, 7};
  per[3][4][4] = {0, 7};
  per[3][4][5] = {0, 8};
  per[3][5][1] = {9, 6};
  per[3][5][2] = {12, 7};
  per[3][5][3] = {0, 8};
  per[3][5][4] = {0, 8};
  per[3][5][5] = {0, 8};
  per[4][1][1] = {3, 5};
  per[4][1][2] = {14, 3};
  per[4][1][3] = {15, 5};
  per[4][1][4] = {17, 5};
  per[4][1][5] = {22, 6};
  per[4][2][1] = {14, 3};
  per[4][2][2] = {0, 6};
  per[4][2][3] = {11, 6};
  per[4][2][4] = {9, 6};
  per[4][2][5] = {17, 7};
  per[4][3][1] = {15, 5};
  per[4][3][2] = {11, 6};
  per[4][3][3] = {0, 7};
  per[4][3][4] = {9, 7};
  per[4][3][5] = {14, 8};
  per[4][4][1] = {17, 5};
  per[4][4][2] = {9, 6};
  per[4][4][3] = {9, 7};
  per[4][4][4] = {0, 8};
  per[4][4][5] = {0, 9};
  per[4][5][1] = {22, 6};
  per[4][5][2] = {17, 7};
  per[4][5][3] = {14, 8};
  per[4][5][4] = {0, 9};
  per[4][5][5] = {0, 9};
  per[5][1][1] = {5, 2};
  per[5][1][2] = {11, 3};
  per[5][1][3] = {12, 2};
  per[5][1][4] = {18, 6};
  per[5][1][5] = {26, 6};
  per[5][2][1] = {11, 3};
  per[5][2][2] = {4, 7};
  per[5][2][3] = {12, 7};
  per[5][2][4] = {13, 7};
  per[5][2][5] = {16, 7};
  per[5][3][1] = {12, 2};
  per[5][3][2] = {12, 7};
  per[5][3][3] = {0, 8};
  per[5][3][4] = {14, 8};
  per[5][3][5] = {11, 8};
  per[5][4][1] = {18, 6};
  per[5][4][2] = {13, 7};
  per[5][4][3] = {14, 8};
  per[5][4][4] = {0, 9};
  per[5][4][5] = {11, 9};
  per[5][5][1] = {26, 6};
  per[5][5][2] = {16, 7};
  per[5][5][3] = {11, 8};
  per[5][5][4] = {11, 9};
  per[5][5][5] = {0, 10};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned int beg_time = clock();
  shit();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  unsigned int end_time = clock();
  return 0;
}
