#include <bits/stdc++.h>
using namespace std;
const int Max = 110000;
const int def = 0x3f3f3f3f;
vector<long long> v[Max];
long long hang[Max], lie[Max], temp[Max];
int cmp(long long x, long long y) { return x > y; }
int main() {
  int i, j;
  long long h;
  int n, m;
  scanf("%d %d", &n, &m);
  if (n <= m) {
    for (i = 1; i <= n; i++) {
      v[i].push_back(0);
      for (j = 1; j <= m; j++) {
        scanf("%lld", &h);
        v[i].push_back(h);
      }
    }
  } else {
    for (j = 1; j <= m; j++) v[j].push_back(0);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%lld", &h);
        v[j].push_back(h);
      }
    }
    swap(n, m);
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      hang[i] += v[i][j];
      lie[j] += v[i][j];
    }
  long long shuchu = 0;
  for (j = 1; j <= m; j++) temp[j] = lie[j];
  sort(temp + 1, temp + 1 + m, cmp);
  long long en = 0;
  for (i = 1; i <= min(4, m); i++) en += temp[i];
  shuchu = max(shuchu, en);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      temp[j] = lie[j] - v[i][j];
    }
    sort(temp + 1, temp + 1 + m, cmp);
    en = hang[i];
    for (j = 1; j <= min(3, m); j++) en += temp[j];
    shuchu = max(shuchu, en);
  }
  if (n >= 2) {
    for (i = 1; i <= n; i++)
      for (j = i + 1; j <= n; j++) {
        en = hang[i] + hang[j];
        for (h = 1; h <= m; h++) temp[h] = lie[h] - v[i][h] - v[j][h];
        long long Max1 = 0, Max2 = 0;
        for (h = 1; h <= m; h++) {
          if (temp[h] > Max1) {
            Max2 = Max1;
            Max1 = temp[h];
          } else if (temp[h] > Max2) {
            Max2 = temp[h];
          }
        }
        en += Max1 + Max2;
        shuchu = max(shuchu, en);
      }
  }
  if (n >= 3) {
    for (j = 1; j <= m; j++) {
      for (i = 1; i <= n; i++) {
        temp[i] = hang[i] - v[i][j];
      }
      sort(temp + 1, temp + 1 + n, cmp);
      en = lie[j];
      for (i = 1; i <= min(3, n); i++) en += temp[i];
      shuchu = max(shuchu, en);
    }
  }
  if (n >= 4) {
    sort(hang + 1, hang + 1 + n, cmp);
    en = 0;
    for (i = 1; i <= 4; i++) en += hang[i];
    shuchu = max(shuchu, en);
  }
  printf("%lld\n", shuchu);
}
