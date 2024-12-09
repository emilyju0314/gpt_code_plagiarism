#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  int nn = n;
  std::vector<int> price;
  std::vector<int> quality;
  int a;
  int b;
  while (nn--) {
    std::cin >> a >> b;
    price.push_back(a);
    quality.push_back(b);
  }
  int p;
  int q;
  std::vector<int> indices;
  for (int k = 0; k < n; k++) indices.push_back(k);
  std::sort(indices.begin(), indices.end(), [&](int i, int j) -> bool {
    return (price[i] < price[j]) ||
           (price[i] == price[j] && quality[i] > quality[j]);
  });
  int bestQual = quality[indices[0]];
  for (int i = 1; i < n; i++) {
    p = price[indices[i]];
    q = quality[indices[i]];
    if (q < bestQual) {
      std::cout << "Happy Alex" << std::endl;
      return 0;
    }
    bestQual = std::max(q, bestQual);
  }
  std::cout << "Poor Alex" << std::endl;
  return 0;
}
