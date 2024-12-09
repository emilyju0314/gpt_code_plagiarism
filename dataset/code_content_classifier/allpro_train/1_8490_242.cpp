#include <bits/stdc++.h>
using namespace std;
long long int arr[200100];
long long int leng(long long int x) {
  long long int len = 0;
  while (x) {
    len++;
    x /= 10;
  }
  return len;
}
map<long long int, long long int> a[11];
int main() {
  long long int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    a[leng(arr[i])][arr[i] % k]++;
  }
  long long int cnt = 0;
  long long int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    long long int z = arr[i];
    for (int j = 1; j < 11; j++) {
      z *= 10;
      z = z % k;
      long long int x = (k - z) % k;
      if (a[j].count(x)) cnt += a[j][x];
      if (j == leng(arr[i])) {
        if (x == arr[i] % k) {
          cnt2++;
        }
      }
    }
  }
  cout << cnt - cnt2 << endl;
}
