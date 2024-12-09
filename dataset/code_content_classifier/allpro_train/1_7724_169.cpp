#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  std::cin >> t;
  while (t--) {
    long long tri1[2], tr12[2];
    std::cin >> tri1[0] >> tri1[1] >> tr12[0] >> tr12[1];
    sort(tri1, tri1 + 2);
    sort(tr12, tr12 + 2);
    if (tri1[0] == tri1[1] || tr12[0] == tr12[1])
      std::cout << "NO\n";
    else {
      if (tri1[1] == tr12[1]) {
        if (tri1[0] + tr12[0] == tr12[1])
          std::cout << "YES\n";
        else
          std::cout << "NO\n";
      } else
        std::cout << "NO\n";
    }
  }
}
