#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  ios::sync_with_stdio(false);
  cin >> n;
  long long int a[n], x, f;
  for (long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int count = 0;
  cin >> x >> f;
  for (long int i = 0; i < n; i++) {
    if (a[i] > x) {
      long long int temp2 = x + f;
      long long int temp = ceil(((double)a[i] + f) / temp2);
      temp--;
      count += temp;
    }
  }
  cout << f * count;
  return 0;
}
