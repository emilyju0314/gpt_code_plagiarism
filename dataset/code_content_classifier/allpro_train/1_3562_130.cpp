#include <bits/stdc++.h>
using namespace std;
const int M = 10 + 10;
long long int lucky[10000];
long long int fac(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans = ans * i;
  }
  return ans;
}
bool islucky(long long int x) {
  bool ok = true;
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) {
      ok = false;
      break;
    }
    x /= 10;
  }
  return ok;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int num = 1;
  long long int id = 1;
  while (n - id + 1 >= 1) {
    num = num * id;
    if (num >= k) {
      break;
    }
    id++;
  }
  if (num < k) {
    cout << "-1" << endl;
  } else {
    long long int idl = n - id + 1;
    long long int idr = n;
    int len = idr - idl + 1;
    int a[M];
    set<int> ilist;
    for (int i = 0; i < len; i++) {
      a[i] = idl + i;
      ilist.insert(i);
    }
    int idx[M];
    int res = len - 1;
    long long int kk = k - 1;
    for (int i = 0; i < len; i++) {
      long long int f = fac(res);
      set<int>::iterator it = ilist.begin();
      for (long long int j = 1; j <= kk / f; j++) {
        it++;
      }
      idx[i] = (*it);
      ilist.erase(idx[i]);
      kk = kk - kk / f * f;
      res--;
    }
    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (islucky(idx[i] + idl) && islucky(a[i])) {
        ans++;
      }
    }
    int num = 0;
    for (int d = 1; d <= 9; d++) {
      for (int i = 0; i < (1 << d); i++) {
        int val = 0;
        for (int k = 0; k < d; k++) {
          if ((i >> k) & 1) {
            val = val * 10 + 4;
          } else {
            val = val * 10 + 7;
          }
        }
        lucky[num++] = val;
      }
    }
    for (int i = 0; i < num; i++) {
      if (lucky[i] < idl) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
