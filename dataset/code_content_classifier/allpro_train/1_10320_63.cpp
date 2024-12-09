#include <bits/stdc++.h>
using namespace std;
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool check(long long int n, long long int p) {
  if (power(n, (p - 1) / 2, p) == 1) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k1, k2, max1 = 0, max2 = 0;
    cin >> n >> k1 >> k2;
    int arr[k1], arr1[k2];
    for (int i = 0; i < k1; i++) {
      cin >> arr[i];
      if (arr[i] > max1) {
        max1 = arr[i];
      }
    }
    for (int i = 0; i < k2; i++) {
      cin >> arr1[i];
      if (arr1[i] > max2) max2 = arr1[i];
    }
    if (max1 > max2) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
