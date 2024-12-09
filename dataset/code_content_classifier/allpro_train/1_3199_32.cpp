#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli SQRT_MAXN = 1000000009LL;

vector<lli> num;

bool isGoodNumber(lli x) {
  if (x <= 0) return false;
  while (x) {
    lli d = x % 10;
    if (d != 2 && d != 8) return false;
    x /= 10;
  }
  return true;
}

void init() {
  num.clear();
  for (lli l = 1; l <= 10; ++l) {
    for (lli i = 0; i < (1 << l); ++i) {
      lli x = 0;
      for (lli j = 0; j < l; ++j) {
        x *= 10;
        if (i >> j & 1) {
          x += 2;
        } else {
          x += 8;
        }
      }
      num.push_back(x);
    }
  }
  sort(num.begin(), num.end());
}

lli rec(lli x, lli k) {
  lli res = isGoodNumber(x) ? 1 : -1;
  for (lli i = k; i < num.size(); ++i) {
    if (x % num[i] == 0) {
      lli tmp = rec(x / num[i], i);
      if (tmp != -1) {
        res = max(res, rec(x / num[i], i) + 1);
      }
    }
  }
  return res;
}

int main() {
  init();
  lli n;
  while (cin >> n) {
    cout << rec(n, 0) << endl;
  }
  return 0;
}