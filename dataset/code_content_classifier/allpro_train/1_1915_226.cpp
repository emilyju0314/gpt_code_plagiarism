#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[3], d;
  cin >> a[0] >> a[1] >> a[2] >> d;
  sort(a, a + 3);
  long long sum = 0;
  if (a[1] - a[0] < d) sum = d - (a[1] - a[0]), a[0] -= (d - (a[1] - a[0]));
  if (a[2] - a[1] < d) sum += d - (a[2] - a[1]), a[2] += (d - (a[2] - a[1]));
  cout << sum << endl;
  return 0;
}
