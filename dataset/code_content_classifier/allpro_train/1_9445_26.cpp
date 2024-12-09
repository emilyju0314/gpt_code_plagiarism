#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long count(long long _m, long long _x) {
    if (_m < 3) {
      return max(0LL, _m);
    }
    m = _m;
    x = _x;
    vector<pair<long long, int>> cnts = factorize(m);
    long long res = 0;
    search(0, 1, cnts, res);
    return res;
  }

 private:
  map<long long, vector<pair<long long, int>>> fs;
  long long m, x;
  long long gcd(long long x, long long y) {
    while (x != 0) {
      y %= x;
      swap(x, y);
    }
    return y;
  }
  vector<pair<long long, int>>& factorize(long long n) {
    if (fs.count(n) > 0) {
      return fs[n];
    }
    vector<pair<long long, int>>& res = fs[n];
    for (long long i = 2; i * i <= n; ++i) {
      int cnt = 0;
      while (n % i == 0) {
        ++cnt;
        n /= i;
      }
      if (cnt > 0) {
        res.emplace_back(i, cnt);
      }
    }
    if (n > 1) {
      res.emplace_back(n, 1);
    }
    return res;
  }
  void search(int i, long long dv, vector<pair<long long, int>>& cnts,
              long long& ans) {
    if (i >= cnts.size()) {
      vector<pair<long long, int>> dvcnts;
      dvcnts.reserve(cnts.size());
      for (auto& pc : cnts) {
        if (pc.second <= 1) {
          continue;
        }
        dvcnts.emplace_back(pc.first, pc.second - 1);
      }
      long long phi = dv;
      for (auto& pc : cnts) {
        long long p = pc.first;
        int c = pc.second;
        if (c == 0) {
          continue;
        }
        dvcnts = merge(dvcnts, factorize(p - 1));
        phi = phi - phi / p;
      }
      ans += phi / calcPeriod(x % dv, dv, dvcnts);
      return;
    }
    long long p = fs[m][i].first;
    long long n = fs[m][i].second;
    for (int j = 0; j <= n; ++j) {
      cnts[i].second = j;
      search(i + 1, dv, cnts, ans);
      dv *= p;
    }
  }
  vector<pair<long long, int>> merge(vector<pair<long long, int>>& list1,
                                     vector<pair<long long, int>>& list2) {
    vector<pair<long long, int>> res;
    res.reserve(list1.size() + list2.size());
    int n = list1.size(), m = list2.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (list1[i].first < list2[j].first) {
        res.emplace_back(list1[i].first, list1[i].second);
        ++i;
      } else if (list1[i].first > list2[j].first) {
        res.emplace_back(list2[j].first, list2[j].second);
        ++j;
      } else {
        res.emplace_back(list1[i].first, list1[i].second + list2[j].second);
        ++i;
        ++j;
      }
    }
    while (i < n) {
      res.emplace_back(list1[i].first, list1[i].second);
      ++i;
    }
    while (j < m) {
      res.emplace_back(list2[j].first, list2[j].second);
      ++j;
    }
    return res;
  }
  long long calcPeriod(long long x, long long mod,
                       vector<pair<long long, int>>& factors) {
    long long phi = 1;
    for (auto& pc : factors) {
      long long p = pc.first;
      int c = pc.second;
      for (int i = 0; i < c; ++i) {
        phi *= p;
      }
    }
    long long res = 1;
    for (auto& pc : factors) {
      long long p = pc.first;
      int c = pc.second;
      long long base = phi;
      for (int i = 0; i < c; ++i) {
        base /= p;
      }
      long long val = powM(x, base, mod);
      int j = c;
      for (int i = 1; i <= c; ++i) {
        if (val == 1) {
          j = i - 1;
          break;
        }
        val = powM(val, p, mod);
      }
      res *= powI(p, j);
    }
    return res;
  }
  long long mulM(long long a, long long b, long long m) {
    long long res = 0;
    while (b > 0) {
      if (b & 0x1) {
        res = (res + a) % m;
      }
      a = (a + a) % m;
      b >>= 1;
    }
    return res;
  }
  long long powM(long long x, long long e, long long m) {
    long long res = 1;
    while (e > 0) {
      if (e & 0x1) {
        res = mulM(res, x, m);
      }
      x = mulM(x, x, m);
      e >>= 1;
    }
    return res;
  }
  long long powI(long long x, long long e) {
    long long res = 1;
    for (int i = 0; i < e; ++i) {
      res *= x;
    }
    return res;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long m, x;
  cin >> m >> x;
  Solution sol;
  cout << sol.count(m, x) << endl;
  return 0;
}
