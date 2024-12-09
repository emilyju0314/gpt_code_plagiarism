#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int primes[15000002];
int no_of_inf[15000002];
vector<int> p;
void seive() {
  for (int i = 0; i < 15000002; i++) {
    primes[i] = 1;
    no_of_inf[i] = 0;
  }
  primes[0] = 0;
  primes[1] = 0;
  for (int i = 2; i < 15000002; i++) {
    if (primes[i]) {
      p.push_back(i);
      for (int j = 2; i * j < 15000002; j++) {
        primes[i * j] = 0;
      }
    }
  }
}
void fact(int x) {
  int y = x;
  for (int i = 0; i < p.size(); i++) {
    if (p[i] * p[i] > x) break;
    if (x % p[i] == 0) {
      no_of_inf[p[i]]++;
      while (x % p[i] == 0) {
        x = x / p[i];
      }
    }
    if (x == 1) break;
  }
  if (x != 1) no_of_inf[x]++;
}
int main() {
  seive();
  int n;
  scanf("%d", &n);
  int a[n];
  int g;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i == 0)
      g = a[0];
    else {
      g = gcd(g, a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = a[i] / g;
    fact(a[i]);
  }
  int what = 0;
  for (int i = 2; i < 15000002; i++) {
    what = max(what, no_of_inf[i]);
  }
  if (what == 0)
    cout << -1;
  else
    cout << n - what;
}
