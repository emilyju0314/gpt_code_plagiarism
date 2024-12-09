#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long int> ans;
unsigned long long int mn(unsigned long long int a, unsigned long long int b) {
  if (a < b) return a;
  return b;
}
int main() {
  unsigned long long int N, f = 2;
  cin >> N;
  N *= f;
  unsigned long long int pow2[66];
  pow2[0] = 1;
  for (int i = 1; i < 64; i++) pow2[i] = pow2[i - 1] * f;
  for (int x = 0; x < 64; x++) {
    unsigned long long int v = pow2[x];
    unsigned long long int high = mn(N / v, sqrt(N)) + 10;
    unsigned long long int low = 1;
    while (low <= high) {
      unsigned long long int mid = (low + high) / 2;
      unsigned long long int val = mid * (mid + v - 3);
      if (val == N) {
        if (mid % 2 == 1) ans.push_back(pow2[x - 1] * mid);
        break;
      }
      if (val > N || val < 0)
        high = mid - 1;
      else
        low = mid + 1;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  if (ans.size() == 0) cout << "-1" << endl;
}
