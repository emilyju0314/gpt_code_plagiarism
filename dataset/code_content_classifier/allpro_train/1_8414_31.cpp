#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++)
    os << *i << (i == end(v) - 1 ? "" : " ");
  return os;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++) is >> *i;
  return is;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  scanf("%d", &n);
  int SQR = sqrt(300000);
  vector<vector<int>> acc_less(SQR + 1);
  for (int j = 1; j <= SQR; j++) {
    acc_less[j].resize(j);
  }
  vector<int> orig(501000, 0);
  for (int i = 0; i < n; i++) {
    int type, a, b;
    scanf("%d %d %d", &type, &a, &b);
    if (type == 1) {
      orig[a] += b;
      for (int t = 1; t <= SQR; t++) {
        acc_less[t][a % t] += b;
      }
    } else if (type == 2) {
      if (a <= SQR)
        printf("%d\n", acc_less[a][b]);
      else {
        int ans = 0;
        for (int j = b; j <= 500000; j += a) ans += orig[j];
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
