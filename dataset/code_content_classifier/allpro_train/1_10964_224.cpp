#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> lab(n);
  for (int i = 0; i < n; ++i) lab[i].resize(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) std::cin >> lab[i][j];
  }
  bool good = true;
  for (int i = 0; good && i < n; ++i)
    for (int j = 0; good && j < n; ++j) {
      if (lab[i][j] > 1) {
        auto row = lab[i];
        std::vector<int> col;
        for (int k = 0; k < n; ++k) col.push_back(lab[k][j]);
        bool found = false;
        for (size_t p = 0; !found && p < row.size(); ++p)
          for (size_t q = 0; !found && q < col.size(); ++q)
            if (row[p] + col[q] == lab[i][j]) found = true;
        if (!found) good = false;
      }
    }
  if (good)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
  return 0;
}
