#include <bits/stdc++.h>
using namespace std;
const int MN = 100111;
int n, a[MN];
int main() {
  ios ::sync_with_stdio(false);
  while (scanf("%d", &n) == 1) {
    for (int i = (1), _b = (n); i <= _b; i++) scanf("%d", &a[i]);
    for (int val = 1, i = 1, j = n; i <= j; ++i, --j, ++val) {
      a[i] -= val;
      if (j != i) a[j] -= val;
    }
    int ln = 0;
    map<int, int> cnt;
    for (int i = (1), _b = (n); i <= _b; i++) {
      cnt[a[i]]++;
      if (a[i] >= 0) ln = max(ln, cnt[a[i]]);
    }
    cout << n - ln << endl;
  }
}
