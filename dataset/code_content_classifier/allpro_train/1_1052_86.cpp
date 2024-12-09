#include <bits/stdc++.h>
using namespace std;
long long Max(long long a, long long b) { return (a < b) ? b : a; }
long long Min(long long a, long long b) { return (a < b) ? a : b; }
int main() {
  long long n;
  cin >> n;
  cout << 2 * n * n - 2 * n + 1;
  exit(0);
}
