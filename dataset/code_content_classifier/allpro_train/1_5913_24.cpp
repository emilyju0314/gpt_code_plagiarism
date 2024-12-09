#include <bits/stdc++.h>
using namespace std;
const int maxint = numeric_limits<int>::max();
const long long maxll = numeric_limits<long long>::max();
const int arr = 2e5 + 10;
const int ar = 2e3 + 10;
const long double pi = acos(-1);
const long long md = 1e9 + 7;
const long double eps = 1e-6;
vector<vector<long long> > operator*(const vector<vector<long long> > a,
                                     const vector<vector<long long> >& b) {
  vector<vector<long long> > res = a;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) res[i][j] = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        res[i][j] = (res[i][j] + a[i][k] * b[k][j] + md) % md;
  return res;
}
const vector<vector<long long> > a = {{4, 0}, {-1, 2}};
vector<vector<long long> > _pow(long long n) {
  if (n == 1) return a;
  if (n % 2 == 1) return a * _pow(n - 1);
  vector<vector<long long> > dop = _pow(n / 2);
  return dop * dop;
}
int main() {
  long long n;
  cin >> n;
  if (n == 0) return cout << 1, 0;
  vector<vector<long long> > use = _pow(n);
  cout << (use[0][0] + use[1][0] + md) % md;
}
