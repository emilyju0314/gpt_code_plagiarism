#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  clock_t start_t = clock();
  clock_t end_t = start_t + 1500;
  while (clock() < end_t)
    ;
  for (long long i = 0; i < n; ++i) {
    cout << v[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
