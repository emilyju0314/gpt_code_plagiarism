#include <bits/stdc++.h>
using namespace std;
void solve(int n, int m) {
  long long maxi, mini;
  if (n - m == 0)
    maxi = 0;
  else
    maxi = (long long)(n - m + 1) * (n - m) / 2;
  long long factor = (n + m - 1) / m;
  int d = (long long)m * (factor)-n;
  if (n % m == 0)
    mini = (long long)m * (factor * (factor - 1)) / 2;
  else
    mini = (long long)(d) * ((factor - 1) * (factor - 2)) / 2 +
           (long long)(m - d) * (factor * (factor - 1)) / 2;
  cout << mini << " " << maxi << endl;
}
int main() {
  int n, m;
  cin >> n >> m;
  solve(n, m);
}
