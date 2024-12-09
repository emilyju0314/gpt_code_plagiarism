#include <bits/stdc++.h>
bool comp(int x, int y) { return x > y; }
void verify(std::vector<int> array) {
  int current = 2048;
  for (unsigned int i = 0; i < array.size(); ++i) {
    current -= array[i];
    if (current < 0) {
      std::cout << "NO\n";
      return;
    } else if (!current) {
      std::cout << "YES\n";
      return;
    }
  }
  if (!current) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}
int main() {
  std::vector<int> array;
  int n, q, val;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    std::cin >> n;
    for (int j = 0; j < n; ++j) {
      std::cin >> val;
      if (val <= 2048) {
        array.push_back(val);
      }
    }
    sort(array.begin(), array.end(), comp);
    verify(array);
    array.clear();
  }
  return 0;
}
