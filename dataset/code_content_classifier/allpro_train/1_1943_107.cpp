#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, d, a[N], b[N];
long long x;
int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int idx[N], c[N];
int main() {
  cin >> n >> d >> x;
  initAB();
  for (int i = 0; i < n; ++i) idx[a[i]] = i;
  vector<int> vec;
  for (int i = 0; i < n; ++i) {
    if (b[i]) vec.push_back(i);
    for (int v = n; v >= 1 && v >= n - 300; v--) {
      int j = idx[v];
      if (i >= j && b[i - j]) {
        c[i] = v;
        break;
      }
    }
    if (!c[i]) {
      for (int z = 0; z < vec.size(); ++z) {
        int k = vec[z];
        c[i] = max(c[i], a[i - k]);
      }
    }
    printf("%d\n", c[i]);
  }
}
