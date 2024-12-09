#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
const long long int mod = 1e9 + 7;
clock_t startTime;
double getCurrenttime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
long long int mod_exp(long long int x, long long int y, long long int mm) {
  if (y <= 0)
    return (1);
  else if (y % 2 == 0)
    return (mod_exp((x * x) % mm, y / 2, mm));
  else
    return ((x * mod_exp((x * x) % mm, (y - 1) / 2, mm)) % mm);
}
bool powerof2(long long int n) {
  return (int)(ceil(log2(n))) == (int(floor(log2(n))));
}
void solve() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  while (n > 0) {
    ans += n;
    n /= 2;
  }
  cout << ans << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
