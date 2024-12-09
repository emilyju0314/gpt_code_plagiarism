#include <bits/stdc++.h>
using namespace std;
unsigned long long fp(unsigned long long n, unsigned long long p) {
  if (p == 0) return 1 % (unsigned long long)(1e9 + 7);
  if (p == 1) return n % (unsigned long long)(1e9 + 7);
  unsigned long long res;
  res = fp(n, p / 2) % (unsigned long long)(1e9 + 7);
  res = (res * res) % (unsigned long long)(1e9 + 7);
  if (p % 2) res = (res * n) % (unsigned long long)(1e9 + 7);
  return res % (unsigned long long)(1e9 + 7);
}
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  unsigned long long pri[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                              31, 37, 41, 43, 47, 53, 59, 61, 67};
  unsigned long long n, a, b;
  vector<unsigned long long> v, arr;
  cin >> n;
  for (int i = 0; i < n; i++) {
    unsigned long long x;
    cin >> x;
    v.push_back(x);
  }
  for (unsigned long long i : v) {
    b = 0;
    for (int j = 0; j < 19; j++) {
      a = 0;
      while (i % pri[j] == 0) {
        a ^= 1;
        i /= pri[j];
      }
      b ^= (a << j);
    }
    for (unsigned long long j : arr) b = min(b, b ^ j);
    if (b > 0) arr.push_back(b);
  }
  cerr << int(arr.size()) << '\n';
  cout << fp(2, n - int(arr.size())) % (unsigned long long)(1e9 + 7) - 1
       << '\n';
  return 0;
}
