#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  int i;
  if (n == 1 || n == 0) return false;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int i = 0, j = 0, k = 0, l = 0, temp;
  int primes[100004];
  for (i = 100003; i >= 0; i--) {
    if (isPrime(i))
      primes[i] = i;
    else
      primes[i] = primes[i + 1];
  }
  int n, m;
  cin >> n >> m;
  int ara[n][m];
  int row[n];
  int col[m];
  for (i = 0; i < n; i++) row[i] = 0;
  for (i = 0; i < m; i++) col[i] = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> temp;
      ara[i][j] = primes[temp] - temp;
      row[k] = row[k] + ara[i][j];
    }
    k++;
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      col[l] = col[l] + ara[j][i];
    }
    l++;
  }
  int ans = row[0];
  for (i = 1; i < n; i++) {
    if (row[i] < ans) ans = row[i];
  }
  for (i = 0; i < m; i++) {
    if (col[i] < ans) ans = col[i];
  }
  cout << ans;
  return 0;
}
