#include <bits/stdc++.h>
using namespace std;
long long int n, h, m, k;
vector<long long int> freight;
int workingTrains(long long int time) {
  if (time - k >= 0) {
    return n - (lower_bound(freight.begin(), freight.end(), time) -
                upper_bound(freight.begin(), freight.end(), time - k));
  } else {
    return upper_bound(freight.begin(), freight.end(),
                       (time - k + m / 2) % (m / 2)) -
           lower_bound(freight.begin(), freight.end(), time);
  }
}
void solve(int test_index) {
  cin >> n >> h >> m >> k;
  freight.resize(n);
  vector<long long int> raw(n);
  for (int i = 0; i < n; i++) {
    long long int hh, mm;
    cin >> hh >> mm;
    freight[i] = (hh * m + mm) % (m / 2);
    raw[i] = freight[i];
  }
  sort(freight.begin(), freight.end());
  long long int t = freight[0], works = workingTrains(freight[0]);
  for (int time : freight) {
    long long int w = workingTrains(time);
    if (works < w) {
      works = w;
      t = time;
    }
  }
  cout << n - works << " " << t << "\n";
  for (int i = 0; i < n; i++) {
    if (t - k < 0) {
      if (raw[i] < t || raw[i] > (t - k + m / 2) % (m / 2)) {
        cout << i + 1 << " ";
      }
    } else {
      if (raw[i] > t - k && raw[i] < t) {
        cout << i + 1 << " ";
      }
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int num_tests = 1;
  for (int test_index = 1; test_index <= num_tests; test_index++) {
    solve(test_index);
  }
  return 0;
}
