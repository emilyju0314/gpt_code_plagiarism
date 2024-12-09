#include <bits/stdc++.h>
using namespace std;
std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
  __duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
  std::cout << "Duration (msec): " << __duration * 1000 << '\n';
}
template <class T>
T min_(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
T max_(T a, T b) {
  return (a > b ? a : b);
}
double EPS = 1e-16;
bool eq_(const double& lhs, const double& rhs) {
  return (fabs(lhs - rhs) < EPS);
}
const int INF = int(2e9);
const long long INF_LL = LLONG_MAX;
const long long MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long gcd(vector<long long>& nums) {
  long long res = nums[0];
  for (int i = 1; i < nums.size(); ++i) res = gcd(nums[i], res);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<pair<int, int> > startnums(N);
  vector<long long> nums(N);
  long long a, b;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    nums[i] = a * b;
    startnums[i] = {a, b};
  }
  long long res = gcd(nums);
  if (res == 1) {
    cout << "-1\n";
    return 0;
  }
  long long res2;
  for (int i = 0; i < N; ++i) {
    res2 = gcd(res, startnums[i].first);
    if (res2 == 1) {
      res2 = gcd(res, startnums[i].second);
    }
    res = res2;
  }
  cout << res << '\n';
  return 0;
}
