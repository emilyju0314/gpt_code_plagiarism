#include <bits/stdc++.h>
using namespace std;
long long int arr[100000 + 5];
long long int capital[100000 + 5];
bool isCapital[100000 + 5];
long long int sumLessCapitals[100000 + 5];
int main() {
  long long int i, j, n, k, u, v, calc, total, noncapital, sum = 0;
  scanf("%lld %lld", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
  }
  for (i = 1; i <= k; i++) {
    scanf("%lld", &capital[i]);
    isCapital[capital[i]] = true;
  }
  noncapital = 0;
  total = 0;
  for (i = 1; i <= n; i++) {
    total += arr[i];
    sumLessCapitals[i] = sumLessCapitals[i - 1];
    if (!isCapital[i]) {
      noncapital += arr[i];
    } else {
      sumLessCapitals[i] += arr[i];
    }
  }
  sum = 0;
  for (i = 2; i <= n; i++) {
    if (isCapital[i] || isCapital[i - 1]) continue;
    sum += arr[i] * arr[i - 1];
  }
  if (!isCapital[1] && !isCapital[n]) {
    sum += arr[1] * arr[n];
  }
  for (i = 1; i <= n; i++) {
    if (isCapital[i]) {
      sum += noncapital * arr[i];
      sum += sumLessCapitals[i - 1] * arr[i];
    }
  }
  cout << sum;
  return 0;
}
