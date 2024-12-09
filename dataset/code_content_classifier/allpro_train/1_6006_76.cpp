#include <bits/stdc++.h>
using namespace std;
long long n, m;
string x, y;
int Hash[1000001][26];
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  cin >> n >> m;
  getchar();
  getline(cin, x);
  getline(cin, y);
  int lenX = x.length(), lenY = y.length();
  int g = gcd(lenX, lenY);
  long long L = lenX * ((long long)lenY / g);
  long long ans = L;
  memset(Hash, 0, sizeof(Hash));
  for (int i = 0; i < lenY; ++i) Hash[i % g][y[i] - 'a']++;
  for (int i = 0; i < lenX; ++i) {
    ans -= Hash[i % g][x[i] - 'a'];
  }
  cout << ans * (n * lenX / L);
  return 0;
}
