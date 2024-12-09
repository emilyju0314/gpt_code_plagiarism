#include <bits/stdc++.h>
using namespace std;
int arahbar[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int arahkol[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int kudabar[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int kudakol[8] = {1, 2, 2, 1, -1, -2, -2, -1};
inline int mutlak(int x) {
  if (x > 0) return x;
  return -x;
}
inline long long mutlak(long long x) {
  if (x > 0) return x;
  return -x;
}
inline int kuadrat(int x) { return x * x; }
inline long long kuadrat(long long x) { return x * x; }
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > hasil;
  int luaran[55];
  for (int i = 0; i < (int)n; i++) {
    int maks = 0;
    for (int j = 0; j < (int)n; j++) {
      int x;
      scanf("%d", &x);
      maks = max(maks, x);
    }
    hasil.push_back(pair<int, int>(maks, i));
  }
  sort(hasil.begin(), hasil.end());
  for (int i = (int)1; i <= (int)n - 1; i++)
    if (hasil[i].first == hasil[i - 1].first) hasil[i].first++;
  for (int i = 0; i < (int)n; i++) luaran[hasil[i].second] = hasil[i].first;
  printf("%d", luaran[0]);
  for (int i = (int)1; i <= (int)n - 1; i++) printf(" %d", luaran[i]);
  printf("\n");
}
