#include <bits/stdc++.h>
using namespace std;
void JIZZ() {
  cout << "";
  exit(0);
}
const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-13;
const long long mod = 1e9 + 7;
int a[12], aft[12];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i], aft[i] = a[i];
  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i - 1]) >= 2) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
}
