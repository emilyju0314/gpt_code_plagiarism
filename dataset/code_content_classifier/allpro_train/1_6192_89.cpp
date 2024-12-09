#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  long long n, h, k;
  cin >> n >> h >> k;
  vector<long long> mas(n);
  for (int i = 0; i < n; i++) cin >> mas[i];
  long long time = 0, currVolume = 0;
  bool have = false;
  for (int i = 0; i < n; i++) {
    long long top = mas[i];
    if (currVolume + top <= h)
      currVolume += top;
    else {
      time += (currVolume / k);
      if (currVolume < k) {
        ++time;
        currVolume = 0;
      }
      currVolume = currVolume % k;
      if (currVolume + top <= h) {
        currVolume += top;
      } else {
        ++time;
        currVolume = top;
      }
    }
  }
  if (currVolume % k != 0) ++time;
  time += currVolume / k;
  cout << time;
  return 0;
}
