#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  set<long long int> numbers;
  map<long long int, long long int> left, right;
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    if (i == 0) {
      numbers.insert(temp);
      continue;
    }
    auto it = numbers.upper_bound(temp);
    if (it != numbers.end() && left.count(*it) == 0) {
      left[*it] = temp;
      cout << *it << " ";
    } else {
      it--;
      right[*it] = temp;
      cout << *it << " ";
    }
    numbers.insert(temp);
  }
  return 0;
}
