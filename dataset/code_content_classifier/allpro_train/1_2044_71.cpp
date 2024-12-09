#include <bits/stdc++.h>
using namespace std;
const long long LMIN = numeric_limits<long long>::min();
const long long LMAX = numeric_limits<long long>::max();
long long n;
vector<long long> g;
int main() {
  cin >> n;
  long long a;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    g.push_back(a);
  }
  sort(g.begin(), g.end());
  cout << g[n / 2];
}
