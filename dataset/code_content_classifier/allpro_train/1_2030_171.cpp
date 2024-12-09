#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, m, k;
  cin >> n >> m >> k;
  long long i = 0;
  vector<pair<long long, long long> > arr;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i % 2 == 0) {
        arr.push_back(make_pair(i + 1, j + 1));
      } else {
        arr.push_back(make_pair(i + 1, m - j));
      }
    }
  }
  long long part = (arr.size() / k);
  long long ptr = 0;
  for (long long i = 0; i < k - 1; i++) {
    cout << part << " ";
    long long j = 0;
    while (j < part) {
      cout << arr[ptr].first << " " << arr[ptr].second << " ";
      ptr++;
      j++;
    }
    cout << '\n';
  }
  if ((arr.size() - ptr) > 0) {
    cout << arr.size() - ptr << " ";
    while (ptr < arr.size()) {
      cout << arr[ptr].first << " " << arr[ptr].second << " ";
      ptr++;
    }
  }
  return 0;
}
