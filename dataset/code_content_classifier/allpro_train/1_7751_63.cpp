#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  std::vector<int> v;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (i == n / i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v[v.size() - 1] << " ";
  int temp = v[v.size() - 1];
  for (int i = v.size() - 2; i >= 0; i--) {
    if (temp % v[i] == 0) {
      temp = v[i];
      cout << v[i] << " ";
    }
  }
  return 0;
}
