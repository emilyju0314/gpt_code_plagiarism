#include <bits/stdc++.h>
using namespace std;
const long long llf = (signed long long)(~0ull >> 1);
template <typename T>
T smax(T x) {
  return x;
}
template <typename T, typename... K>
T smax(T x, K... args) {
  return max(x, smax(args...));
}
long long gcd(long long a, long long b) { return (b) ? gcd(b, a % b) : a; }
int count_dif(vector<long long>& a) {
  sort(a.begin(), a.end());
  long long x = -llf;
  int ret = 0;
  for (auto y : a) {
    if (y ^ x) {
      x = y;
      ret++;
    }
  }
  return ret;
}
void calc(vector<long long> a, long long& g, long long& first, int& cnt) {
  sort(a.begin(), a.end());
  long long d1 = a[1] - a[0], d2 = a[2] - a[0], d3 = a[3] - a[0];
  g = gcd(d1, gcd(d2, d3));
  if (!g) {
    first = a[0];
    cnt = 0;
    return;
  }
  cnt = 0;
  first = (a[0] % g + g) % g;
  for (auto x : a) cnt += ((x - first) / g) & 1;
}
vector<pair<long long, long long>> solve(vector<long long> a) {
  vector<pair<long long, long long>> ret;
  long long g, fr;
  int _;
  calc(a, g, fr, _);
  auto work = [&](int i, int j) {
    if (a[i] == a[j]) return;
    ret.emplace_back(a[i], a[j]);
    a[i] = a[j] * 2 - a[i];
  };
  while (count_dif(a) > 2) {
    long long d1 = a[1] - a[0], d2 = a[2] - a[1], d3 = a[3] - a[2];
    long long mxd = smax(d1, d2, d3);
    if (d1 == mxd) {
      if (a[1] * 2 - a[0] <= a[3]) {
        work(0, 1);
      } else {
        if ((d3 + d2) * 2 <= d1) {
          work(3, 1);
        } else {
          work(0, 1);
        }
      }
    } else if (d2 == mxd) {
      if (d1 > d3) {
        if (d2 > (d1 << 1)) {
          work(2, 1);
          work(2, 0);
        } else {
          work(0, 1);
        }
      } else {
        if (d2 > (d3 << 1)) {
          work(1, 2);
          work(1, 3);
        } else {
          work(3, 2);
        }
      }
    } else {
      if (a[2] * 2 - a[3] >= a[0]) {
        work(3, 2);
      } else {
        if (2 * (d1 + d2) < d3) {
          work(0, 2);
        } else {
          work(3, 2);
        }
      }
    }
  }
  vector<vector<int>> grp;
  auto get_grp = [&](vector<long long>& a) {
    grp.clear();
    sort(a.begin(), a.end());
    grp.push_back({0});
    for (int i = 1; i < 4; i++)
      if (a[i] == a[i - 1])
        grp.back().push_back(i);
      else
        grp.push_back({i});
  };
  auto work_grp = [&](int i, int j) {
    for (auto x : grp[i]) {
      work(x, grp[j][0]);
    }
  };
  if (a[0] < 0) {
    work(0, 3);
    if (count_dif(a) == 2 && a[0] == fr) return ret;
    while (count_dif(a) <= 2) work(0, 3);
    while (get_grp(a),
           fr - a[3] > 5 * g || a[grp[2][0]] - a[grp[1][0]] >= 5 * g) {
      long long d1 = a[grp[1][0]] - a[0], d2 = a[grp[2][0]] - a[grp[1][0]];
      assert(d1 <= d2);
      assert(a[0] < fr);
      if (a[3] + d1 + d2 < fr) {
        work_grp(0, 2);
      } else if (a[3] + d2 < fr) {
        work_grp(0, 2);
        work_grp(1, 2);
        work_grp(0, 1);
      } else {
        work_grp(0, 1);
        work_grp(2, 0);
      }
    }
    while (get_grp(a), true) {
      long long d1 = a[grp[1][0]] - a[0], d2 = a[grp[2][0]] - a[grp[1][0]];
      if (d1 == d2) {
        work_grp(0, 1);
        break;
      } else if (d1 > d2) {
        work_grp(2, 1);
      } else {
        work_grp(0, 1);
      }
    }
    while (get_grp(a), a[0] != fr) {
      work_grp(0, 1);
    }
  } else if (a[0] >= g) {
    work(3, 0);
    if (count_dif(a) == 2 && a[0] == fr) return ret;
    while (count_dif(a) <= 2) work(3, 0);
    while (get_grp(a), a[0] - fr > 5 * g || a[grp[1][0]] - a[0] >= 5 * g) {
      long long d1 = a[grp[1][0]] - a[0], d2 = a[grp[2][0]] - a[grp[1][0]];
      assert(d1 >= d2);
      if (a[0] - d1 - d2 > fr) {
        work_grp(2, 0);
      } else if (a[0] - d1 > fr) {
        work_grp(2, 0);
        work_grp(1, 0);
        work_grp(2, 1);
      } else {
        work_grp(2, 1);
        work_grp(0, 2);
      }
    }
    while (get_grp(a), true) {
      long long d1 = a[grp[1][0]] - a[0], d2 = a[grp[2][0]] - a[grp[1][0]];
      if (d1 == d2) {
        work_grp(2, 1);
        break;
      } else if (d1 > d2) {
        work_grp(2, 1);
      } else {
        work_grp(0, 1);
      }
    }
    while (get_grp(a), a[0] != fr) {
      work_grp(1, 0);
    }
  }
  return ret;
}
void read(vector<long long>& a) {
  a.resize(4);
  for (int i = 0; i < 4; i++) scanf("%lld", a.data() + i);
}
int main() {
  vector<long long> A, B;
  read(A);
  read(B);
  long long ga, fa, gb, fb;
  int ca, cb;
  calc(A, ga, fa, ca);
  calc(B, gb, fb, cb);
  if ((ga ^ gb) || (fa ^ fb) || (ca ^ cb)) {
    puts("-1");
    return 0;
  }
  if (!ga) {
    puts("0");
    return 0;
  }
  vector<pair<long long, long long>> retA = solve(A);
  vector<pair<long long, long long>> retB = solve(B);
  reverse(retB.begin(), retB.end());
  printf("%d\n", (signed)(retA.size() + retB.size()));
  for (auto x : retA) printf("%lld %lld\n", x.first, x.second);
  for (auto x : retB) printf("%lld %lld\n", 2 * x.second - x.first, x.second);
  return 0;
}
