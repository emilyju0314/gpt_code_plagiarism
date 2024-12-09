#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int L = 30;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<tuple<char, int, int, int>> opt;

  int top = 2;

  auto cmp = [&](int i, int j) {
    opt.emplace_back('<', i, j, ++top);
    return top;
  };
  auto sum = [&](int i, int j) {
    opt.emplace_back('+', i, j, ++top);
    return top;
  };
  auto CMP = [&](int i, int j, int k) { opt.emplace_back('<', i, j, k); };
  auto SUM = [&](int i, int j, int k) { opt.emplace_back('+', i, j, k); };
  auto MOV = [&](int i, int j) { opt.emplace_back('+', 2, i, j); };

  int ONE, ZERO = 2;
  {
    int x0 = cmp(2, 0);
    int x1 = cmp(2, 1);
    int m1 = sum(x0, x1);
    ONE = cmp(2, m1);
  }

  vector<int> power(L);
  power[0] = ONE;
  for (int i = 1; i < L; ++i)
    power[i] = sum(power[i - 1], power[i - 1]);
  vector<int> m1(L);
  m1[0] = ZERO;
  for (int i = 1; i < L; ++i)
    m1[i] = sum(m1[i - 1], power[i - 1]);

  auto getbit = [&](int i) {
    vector<int> ret(L);
    int csum = ZERO;
    for (int j = L - 1; j >= 0; --j) {
      int tmp = cmp(sum(csum, m1[j]), i);
      MOV(tmp, ++top);
      ret[j] = top;
      for (int rep = 0; rep < j; ++rep) SUM(tmp, tmp, tmp);
      csum = sum(csum, tmp);
    }
    return ret;
  };

  auto ga = getbit(0), gb = getbit(1);

  auto mul1 = [&](int i, int j) {
    return cmp(ONE, sum(i, j));
  };

  vector<int> tot(L * 2 - 1);
  for (int i = 0; i < L * 2 - 1; ++i) tot[i] = ++top;
  for (int i = 0; i < L; ++i)
    for (int j = 0; j < L; ++j)
      SUM(tot[i + j], mul1(ga[i], gb[j]), tot[i + j]);
  for (int i = L * 2 - 2; i >= 0; --i) {
    SUM(2, 2, 2);
    SUM(tot[i], 2, 2);
  }

  cout << opt.size() << '\n';
  for (auto [c, i, j, k] : opt) {
    cout << c << ' ' << i << ' ' << j << ' ' << k << '\n';
  }

#ifdef ELEGIA
  vector<ll> a(200000);
  cin >> a[0] >> a[1];
  for (auto [c, i, j, k] : opt) {
    if (c == '<')
      a[k] = a[i] < a[j];
    else
      a[k] = a[i] + a[j];
  }
  cout << a[2] << '\n';
#endif

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
