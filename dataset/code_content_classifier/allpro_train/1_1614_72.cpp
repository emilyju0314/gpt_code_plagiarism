#include <bits/stdc++.h>
using namespace std;
const int mx = 100010;
int a[mx], n;
class ui_t {
 public:
  unsigned long long m[4];
  ui_t(unsigned long long x) {
    m[0] = x % 0x100000000;
    m[1] = x / 0x100000000;
    m[2] = 0;
    m[3] = 0;
  }
  ui_t& operator*=(unsigned long long x) {
    unsigned long long keep = 0;
    for (int i = 0; i < 4; i++) {
      m[i] = keep + m[i] * x;
      keep = m[i] / 0x100000000;
      m[i] %= 0x100000000;
    }
    return *this;
  }
  bool operator<(const ui_t& o) const {
    for (int i = 3; i >= 0; i--) {
      if (m[i] < o.m[i]) return true;
      if (m[i] > o.m[i]) return false;
    }
    return false;
  }
  bool operator==(const ui_t& o) const {
    for (int i = 0; i < 4; i++) {
      if (m[i] != o.m[i]) return false;
    }
    return true;
  }
};
struct TFeatures {
  int leftmin, rightmin;
  int leftmin_cnt, rightmin_cnt;
} features[mx];
int main(int argc, char* argv[]) {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int mmin, nmin;
  int leftmin = a[1];
  int leftmin_cnt = 1;
  for (int i = 2; i < n; i++) {
    features[i].leftmin = leftmin;
    features[i].leftmin_cnt = leftmin_cnt;
    if (a[i] < leftmin) {
      leftmin = a[i];
      leftmin_cnt = 1;
    } else if (a[i] == leftmin) {
      leftmin_cnt++;
    }
  }
  int rightmin = a[n];
  int rightmin_cnt = 1;
  for (int i = n - 1; i > 1; i--) {
    features[i].rightmin = rightmin;
    features[i].rightmin_cnt = rightmin_cnt;
    if (a[i] < rightmin) {
      rightmin = a[i];
      rightmin_cnt = 1;
    } else if (a[i] == rightmin) {
      rightmin_cnt++;
    }
  }
  long long minProd = -1;
  long long r = 0;
  ui_t mi(0);
  for (int i = 2; i < n; i++) {
    ui_t m(features[i].leftmin);
    m *= a[i];
    m *= features[i].rightmin;
    if (i == 2 || m < mi)
      mi = m, r = 1ll * features[i].leftmin_cnt * features[i].rightmin_cnt;
    else if (m == mi)
      r += 1ll * features[i].leftmin_cnt * features[i].rightmin_cnt;
  }
  printf("%lld\n", r);
  return 0;
}
