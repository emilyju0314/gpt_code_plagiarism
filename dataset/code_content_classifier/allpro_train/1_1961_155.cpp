#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n >> x;
  if (n == 2 && x == 0) {
    cout << "NO" << '\n';
    return 0;
  } else if (n == 1) {
    cout << "YES" << '\n';
    cout << x << '\n';
    return 0;
  } else if (n == 2) {
    cout << "YES" << '\n';
    cout << 0 << ' ' << x << '\n';
    return 0;
  }
  int i;
  vector<int> answer;
  int x1 = 0;
  answer.push_back(1 << 17);
  answer.push_back(1 << 18);
  x1 ^= (1 << 17);
  x1 ^= (1 << 18);
  for (i = 0; i < n - 3; i++) answer.push_back(i), x1 ^= i;
  answer.push_back(x1 ^ x);
  cout << "YES" << '\n';
  for (i = 0; i < n; i++) cout << answer[i] << ' ';
  cout << '\n';
  return 0;
}
