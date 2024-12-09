#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!a) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
const long long MOD = 1e9 + 7;
const long long mod = 1e9 + 7;
void sout() { cout << "\n"; }
template <typename T, typename... Types>
void sout(T var1, Types... var2) {
  cout << var1 << " ";
  sout(var2...);
}
template <typename T>
void sout(vector<T> arr) {
  for (auto it : arr) {
    cout << it << " ";
  }
  sout();
}
long long n, k;
vector<long long> arr;
pair<long long, long long> a, b;
bool fun(long long mid) {
  long long lc = lcm(a.second, b.second);
  long long amount = 0;
  long long com = mid / lc;
  long long i = 0;
  for (long long j = 0; j < (long long)(com); j++) {
    amount += arr[i] * (a.first + b.first);
    i++;
  }
  long long x = mid / a.second - com;
  long long y = mid / b.second - com;
  if (a.first > b.first) {
    while (x) {
      x--;
      amount += arr[i] * a.first;
      i++;
    }
    while (y--) {
      amount += arr[i] * b.first;
      i++;
    }
  } else {
    while (y--) {
      amount += arr[i] * b.first;
      i++;
    }
    while (x) {
      x--;
      amount += arr[i] * a.first;
      i++;
    }
  }
  return amount >= k;
}
void test_case() {
  cin >> n;
  arr.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] = arr[i] / 100;
  }
  sort(arr.begin(), arr.end(), greater<long long>());
  cin >> a.first;
  cin >> a.second;
  cin >> b.first;
  cin >> b.second;
  cin >> k;
  long long ans = 1e9;
  long long l = 1;
  long long r = n;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    bool check = fun(mid);
    if (check) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (ans == 1e9) {
    ans = -1;
  }
  sout(ans);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long t = 1;
  cin >> t;
  while (t--) {
    test_case();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
