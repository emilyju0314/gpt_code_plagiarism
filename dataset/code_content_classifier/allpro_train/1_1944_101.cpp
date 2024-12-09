#include <bits/stdc++.h>
using namespace std;
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int dx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
const int N = 1e5 + 5, MOD = 1e9 + 7;
int main() {
  file();
  fast();
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] += a[i - 1];
  }
  map<long long, int> mp;
  long long sum = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] % 2 == 0 && a[i] / 2 == a[n - 1] - a[i] &&
        mp.find(a[i] / 2) != mp.end())
      sum += mp[a[i] / 2];
    mp[a[i]]++;
  }
  cout << sum;
}
