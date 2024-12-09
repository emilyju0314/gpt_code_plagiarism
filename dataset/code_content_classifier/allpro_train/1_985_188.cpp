#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << -1 << "\n";
    return 0;
  }
  vector<long long> vll;
  for (long long temp = 0; cin >> temp;) vll.push_back(temp);
  sort(vll.begin(), vll.end());
  reverse(vll.begin(), vll.end());
  long long temp;
  int i = 0;
  for (; i < k; i++) temp = vll[i];
  if (i < vll.size()) {
    if (temp == vll[i]) {
      cout << -1 << "\n";
    }
    cout << temp << " " << temp << "\n";
  } else
    cout << temp << " " << temp << "\n";
  return 0;
}
