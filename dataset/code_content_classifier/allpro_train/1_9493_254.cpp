#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, x;
  map<int, int> par;
  cin >> n >> k;
  long long int br = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    br += par[k ^ x];
    par[x]++;
  }
  cout << br;
  return 0;
}
