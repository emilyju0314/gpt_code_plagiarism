#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, x;
  cin >> n >> k >> x;
  long long int sk = 1;
  while (k--) sk *= x;
  vector<long long int> v(n);
  vector<long long int> acum_left(n);
  vector<long long int> acum_right(n);
  vector<long long int> calc_max(n);
  long long int a_l = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    a_l = a_l | v[i];
    acum_left[i] = a_l;
  }
  long long int a_r = 0;
  for (long long int i = n - 1; i >= 0; i--) {
    a_r = a_r | v[i];
    acum_right[i] = a_r;
    long long int ar = 0;
    if (i + 1 < n) ar = acum_right[i + 1];
    long long int al = 0;
    if (i > 0) al = acum_left[i - 1];
    calc_max[i] = ar | al | (v[i] * sk);
    if (i == 0) break;
  }
  cout << *max_element(calc_max.begin(), calc_max.end()) << endl;
}
