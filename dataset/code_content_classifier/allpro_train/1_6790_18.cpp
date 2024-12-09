#include <bits/stdc++.h>
using namespace std;
vector<long long> scan_array(long long n) {
  vector<long long> m(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  return m;
}
bool is_prime(long long x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
const long long MAX_SIZE = 100001;
vector<long long> m(MAX_SIZE);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n, i;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    m[a] += a;
  }
  for (i = 2; i <= MAX_SIZE; i++) {
    m[i] = max(m[i - 1], m[i] + m[i - 2]);
  }
  cout << m[i - 1];
  return 0;
}
