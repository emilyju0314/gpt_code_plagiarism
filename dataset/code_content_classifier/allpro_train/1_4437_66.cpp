#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int i = 0, j = n - 1, l = n - 1, k = n - 2;
  vector<long long> res(n, -1);
  while (i <= j) {
    if (i != j) {
      res[i] = arr[l];
      res[j] = arr[k];
    } else
      res[i] = arr[l];
    i += 2;
    j -= 2;
    k -= 2;
    l -= 2;
  }
  i = 0;
  l = 0;
  while (i < n) {
    if (res[i] == -1) {
      res[i] = arr[l];
      l++;
    }
    i++;
  }
  if (n % 2 == 0) {
    cout << n / 2 - 1 << endl;
  } else
    cout << n / 2 << endl;
  for (int c : res) {
    cout << c << " ";
  }
  return 0;
}
