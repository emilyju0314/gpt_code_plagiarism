#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> c(2);
vector<long long> t1;
void ini(long long n, long long k) {
  c[0] = 0;
  c[1] = (2 * n - 1) - k;
}
void merrr(long long l, long long r) {
  if (l == r) {
    return;
  }
  long long mid = (l + r - 1) / 2;
  merrr(l, mid);
  merrr(mid + 1, r);
  if ((c[0] + 2) <= c[1]) {
    t1.clear();
    for (long long i = l; i <= r; i++) t1.push_back(a[i]);
    sort(t1.begin(), t1.end());
    for (long long i = l; i <= r; i++) a[i] = t1[i - l];
    c[0] += 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long n, k;
  cin >> n >> k;
  long long temp;
  temp = 2 * n - 1;
  if ((temp - k) % 2 == 1 || k > (2 * n)) {
    cout << -1 << endl;
    return 0;
  }
  ini(n, k);
  for (long long i = n; i >= 1; i--) a.push_back(i);
  merrr(0, n - 1);
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
