#include <bits/stdc++.h>
using namespace std;
struct less_way {
  bool operator()(const pair<uint32_t, uint32_t>& p1,
                  const pair<uint32_t, uint32_t>& p2) {
    return p1.first < p2.first ||
           (p1.first == p2.first && p1.second > p2.second);
  }
};
int32_t h_y, h_m, h_c;
int32_t a_y, a_m, a_c;
int32_t d_y, d_m, d_c;
bool check(int32_t h_y, int32_t a_y, int32_t d_y) {
  int32_t dd_y = max(0, a_y - d_m);
  if (!dd_y) {
    return false;
  }
  int32_t dd_m = max(0, a_m - d_y);
  int32_t t = h_m / dd_y + (h_m % dd_y ? 1 : 0);
  return h_y > dd_m * t;
}
int main() {
  cin >> h_y >> a_y >> d_y;
  cin >> h_m >> a_m >> d_m;
  cin >> h_c >> a_c >> d_c;
  uint32_t max_t = 100000;
  uint32_t min_c = -1;
  for (uint32_t h = 0; h <= max_t; h++) {
    uint32_t c = h * h_c;
    if (c >= min_c) {
      break;
    }
    for (uint32_t a = 0; a <= max_t; a++) {
      uint32_t tc = c + a * a_c;
      if (tc >= min_c) {
        break;
      }
      for (uint32_t d = 0; d <= max_t; d++) {
        uint32_t ttc = tc + d * d_c;
        if (ttc >= min_c) {
          break;
        }
        if (check(h_y + h, a_y + a, d_y + d)) {
          min_c = ttc;
        }
      }
    }
  }
  cout << min_c;
  return 0;
}
