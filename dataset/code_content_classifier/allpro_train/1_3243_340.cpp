#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, M = 1e9, OO = 0x3f3f3f3f;
const long long int MOD = 1e9 + 7;
vector<int> numbers;
void lucky(long long int num) {
  if (num > M) return;
  if (num) numbers.push_back(num);
  lucky(num * 10 + 4);
  lucky(num * 10 + 7);
}
int main() {
  int n;
  scanf("%d", &n);
  lucky(0);
  sort(numbers.begin(), numbers.end());
  cout << lower_bound(numbers.begin(), numbers.end(), n) - numbers.begin() + 1;
  return 0;
}
