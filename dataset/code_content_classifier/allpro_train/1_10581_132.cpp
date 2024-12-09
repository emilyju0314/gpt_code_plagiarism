#include <bits/stdc++.h>
static constexpr int MAXN = 5000;
static constexpr int INF = std::numeric_limits<int>::max();
int main() {
  int size;
  std::scanf("%d", &size);
  std::vector<int> vec(size);
  std::unordered_map<int, int> count;
  for (int i = 0; i < size; i++) {
    std::scanf("%d", &vec[i]);
    count[vec[i]]++;
  }
  std::sort(vec.begin(), vec.end());
  vec.resize(std::unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i + 1 < vec.size(); i++) {
    if (vec[i + 1] - vec[i] != 1) {
      std::puts("NO");
      return EXIT_SUCCESS;
    }
  }
  for (int i = 1; i + 1 < vec.size(); i++) {
    if (count[vec[i]] < 2) {
      std::puts("NO");
      return EXIT_SUCCESS;
    }
  }
  for (int i = 1; i < vec.size(); i++) {
    count[vec[i]] -= count[vec[i - 1]];
    if (count[vec[i]] < 0) {
      std::puts("NO");
      return EXIT_SUCCESS;
    }
  }
  if (count[vec.back()] != 0) {
    std::puts("NO");
    return 0;
  }
  std::puts("YES");
  return EXIT_SUCCESS;
}
