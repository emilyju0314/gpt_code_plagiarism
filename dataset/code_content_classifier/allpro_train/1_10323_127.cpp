#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  long long t = 0;
  while (t++ < T) {
    long long n;
    cin >> n;
    long long a[n];
    vector<long long> count(n, 0);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      count[a[i] % n]++;
    }
    long long max = *max_element(count.begin(), count.end());
    long long d = 0;
    long long ans;
    for (long long i = 0; i < n; i++)
      if (count[i] > 0) d++;
    if (d == max)
      ans = max - 1;
    else if (d < max)
      ans = d;
    else if (d > max)
      ans = max;
    cout << ans << endl;
  }
  return 0;
}
