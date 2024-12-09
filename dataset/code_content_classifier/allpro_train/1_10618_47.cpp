#include <bits/stdc++.h>
using namespace std;
vector<int> rs_needed[1000000 + 5];
int arr[1000000 + 5];
int main() {
  int i, j, k, n, idx = 0, rs, lst_pos, cminus = 0, cplus = 0;
  long long int dv = 0, mn;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    dv += abs(arr[i] - i);
  }
  mn = dv;
  for (i = 1; i <= n; i++) {
    if (arr[i] > i) {
      rs_needed[arr[i] - i].push_back(arr[i]);
      cminus++;
    } else {
      rs_needed[n - i + arr[i]].push_back(arr[i]);
      cplus++;
    }
  }
  lst_pos = n;
  for (rs = 0; rs < n; rs++) {
    if (dv < mn) mn = dv, idx = rs;
    for (auto x : rs_needed[rs]) {
      cminus--;
      cplus++;
    }
    dv -= n - arr[lst_pos];
    dv += arr[lst_pos];
    lst_pos--;
    cplus--;
    cminus++;
    dv = dv + cplus - cminus;
  }
  printf("%lld %d\n", mn, idx);
  return 0;
}
