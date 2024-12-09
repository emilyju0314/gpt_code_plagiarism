#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, mid;
  cin >> n >> k;
  if (n % 2 == 0)
    mid = n / 2;
  else
    mid = (n / 2) + 1;
  if (k <= mid)
    i = k * 2 - 1;
  else
    i = (k - mid) * 2;
  cout << i;
  return 0;
}
