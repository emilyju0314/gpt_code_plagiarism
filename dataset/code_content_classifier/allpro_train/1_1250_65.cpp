#include <bits/stdc++.h>
using namespace std;
long long n, d;
vector<long long> v;
bool f(int l, int x) {
  if (v[x] - v[l] <= d)
    return true;
  else
    return false;
}
int binsearch(int l) {
  int low = l;
  int high = n;
  int mid = (low + high) / 2;
  while (low < high) {
    mid = low + (high - low + 1) / 2;
    if (f(l, mid))
      low = mid;
    else
      high = mid - 1;
  }
  return low;
}
int main() {
  cin >> n >> d;
  v = vector<long long>(n + 1);
  for (long long i = 1; i <= n; i++) cin >> v[i];
  long long a = 0, ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans = binsearch(i);
    a += max(((ans - i) * (ans - i - 1)) / 2, 0LL);
  }
  cout << a;
}
