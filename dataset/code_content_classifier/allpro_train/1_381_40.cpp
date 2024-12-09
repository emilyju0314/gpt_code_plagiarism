#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double pi = 3.1415926535897932;
const double E = 2.7182818284590452354;
const int Max_Bit = 63;
const int INF = 2000000000;
const long long LINF = 1000000000000000007ll;
const int MOD = 1000000007;
const int NMAX = 100001;
const int MMAX = 100001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n, k;
  cin >> n >> k;
  int p[NMAX], t = 0;
  for (int i = 1; i <= k; i++) {
    int m;
    cin >> m;
    for (int j = 1; j <= m; j++) cin >> p[j];
    int curt = 1;
    if (p[1] == 1)
      for (int j = 2; j <= m; j++) {
        if (p[j] != p[j - 1] + 1) break;
        curt = j;
      }
    t += (m - curt) * 2;
  }
  t += k - 1;
  cout << t << endl;
  return 0;
}
