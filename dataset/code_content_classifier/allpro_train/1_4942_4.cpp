#include <bits/stdc++.h>
using namespace std;
long long n, one, two, three, cnt, m, arr[100];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  m = 100000;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) m = min(m, arr[i]);
  for (int i = 0; i < n; i++)
    if (arr[i] == m) cnt++;
  if (cnt > n / 2)
    cout << "Bob\n";
  else
    cout << "Alice\n";
  return 0;
}
