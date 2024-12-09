#include <bits/stdc++.h>
using namespace std;
size_t getPowIdx(int number, const vector<int>& powersOfTwo) {
  size_t i = 1;
  while (number % powersOfTwo[i] == 0) {
    ++i;
  }
  return i - 1;
}
void solve(vector<int>& result, int n, int k) {
  if (n == 1) {
    result.insert(result.end(), {k});
    return;
  } else if (n == 2) {
    result.insert(result.end(), {k, 2 * k});
    return;
  } else if (n == 3) {
    result.insert(result.end(), {k, k, 3 * k});
    return;
  }
  for (size_t i = 0; i < n / 2 + n % 2; ++i) {
    result.push_back(k);
  }
  solve(result, n / 2, k * 2);
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(10);
  int n;
  cin >> n;
  vector<int> result;
  solve(result, n, 1);
  for (auto v : result) {
    cout << v << ' ';
  }
  cout << '\n';
  return 0;
}
