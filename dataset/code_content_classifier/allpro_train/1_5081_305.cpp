#include <bits/stdc++.h>
using namespace std;
string qw = "abcdefghijklmnopqrstuvwxyz";
long long int n, m, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  long long int a[10] = {0};
  long long int b[10] = {0};
  long long int c[n];
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    c[i] = x;
    a[x]++;
  }
  for (long long int i = 0; i < m; i++) {
    long long int x;
    cin >> x;
    b[x]++;
  }
  for (long long int i = 0; i < n; i++) {
    if (b[c[i]]) {
      cout << c[i] << " ";
    }
  }
  return 0;
}
