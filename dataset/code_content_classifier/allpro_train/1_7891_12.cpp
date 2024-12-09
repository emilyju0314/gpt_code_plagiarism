#include <bits/stdc++.h>
using namespace std;
long long gcdcomp(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcdcomp(b, a);
}
int main() {
  int N;
  cin >> N;
  vector<long long> v(N, 0);
  long long gcd, facts = 0;
  for (int i = 0; i < N; i++) cin >> v[i];
  gcd = v[0];
  for (int i = 1; i < N; i++) {
    if (gcd > v[i])
      gcd = gcdcomp(gcd, v[i]);
    else
      gcd = gcdcomp(v[i], gcd);
  }
  for (int i = 1; i <= sqrt(gcd); i++) {
    if (gcd % i == 0) {
      if (gcd / i == i)
        facts++;
      else
        facts += 2;
    }
  }
  cout << facts << endl;
}
