#include <bits/stdc++.h>
using namespace std;
set<long long int> s;
void init(long long int n) {
  vector<long long int> res;
  for (long long int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    res.push_back(n);
  }
  for (auto i : res) {
    s.insert(i);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  init(v[0] * v[1]);
  long long int p = 1;
  for (auto it : s) {
    long long int min1 = 1e14, min2 = 1e14;
    for (long long int i = 0; i < n; i++) {
      long long int a = 0;
      while (v[i] % it == 0) {
        v[i] /= it;
        a++;
      }
      if (a <= min1) {
        min2 = min1;
        min1 = a;
      } else if (a <= min2) {
        min2 = a;
      }
    }
    long long int i = 0;
    while (i < min2) {
      p *= it;
      i++;
    }
  }
  cout << p;
  return 0;
}
