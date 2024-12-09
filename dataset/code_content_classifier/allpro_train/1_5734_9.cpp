#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  int n = (int)str.length();
  cout << 3 << '\n';
  cout << "R " << n - 1 << '\n';
  cout << "L " << n << '\n';
  cout << "L " << 2 << '\n';
  return 0;
}
