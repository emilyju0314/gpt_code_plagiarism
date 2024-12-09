#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, mn, mx;
  cin >> n >> m >> mn >> mx;
  long long t[110], M = -1, N = 999999999;
  for (long long i = 0; i < m; i++) {
    cin >> t[i];
    M = max(M, t[i]);
    N = min(N, t[i]);
  }
  if (M > mx || N < mn) return cout << "Incorrect\n", 0;
  n -= m;
  if (n == 1) {
    if (mn == N || mx == M) return cout << "Correct\n", 0;
    return cout << "Incorrect\n", 0;
  }
  cout << "Correct\n", 0;
  return 0;
}
