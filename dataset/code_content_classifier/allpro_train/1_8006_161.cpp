#include <bits/stdc++.h>
using namespace std;
void basketball() {
  long long int n, m, d, w2c(0), l2c(0), maxa(0), maxb(0), maxdiff(0), a, b,
      diff;
  list<long long int> w, l;
  set<long long int> dist;
  cin >> n;
  dist.insert(0);
  for (int i = 0; i < n; ++i) {
    cin >> d;
    w.push_back(d);
    dist.insert(d);
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> d;
    l.push_back(d);
    dist.insert(d);
  }
  w.sort();
  l.sort();
  for (auto dit = dist.begin(); dit != dist.end(); ++dit) {
    int temp_wc(0), temp_lc(0);
    for (auto it = w.begin(); it != w.end(); ++it) {
      if (*it <= *dit) {
        ++w2c;
        ++temp_wc;
      } else
        break;
    }
    for (long long int i = 0; i < temp_wc; ++i) {
      w.pop_front();
    }
    for (auto it = l.begin(); it != l.end(); ++it) {
      if (*it <= *dit) {
        ++l2c;
        ++temp_lc;
      } else
        break;
    }
    for (long long int i = 0; i < temp_lc; ++i) {
      l.pop_front();
    }
    a = 2 * w2c + (n - w2c) * 3;
    b = 2 * l2c + (m - l2c) * 3;
    diff = a - b;
    if (dit == dist.begin()) {
      maxdiff = diff;
      maxa = a;
      maxb = b;
    } else {
      if (diff > maxdiff) {
        maxdiff = diff;
        maxa = a;
        maxb = b;
      } else if (diff == maxdiff && a > maxa) {
        maxa = a;
        maxb = b;
      } else {
      }
    }
  }
  cout << maxa << ":" << maxb;
}
int main() {
  basketball();
  return 0;
}
