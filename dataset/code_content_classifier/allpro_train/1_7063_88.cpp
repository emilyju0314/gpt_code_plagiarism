#include <bits/stdc++.h>
using namespace std;
const int MX = 300002;
long long N;
int ans[MX], arr[MX], was[MX];
int take;
void f(int L, int R, int vL, int vR) {
  if (L > R) return;
  if (vL == vR) {
    for (int i = L; i <= R; i++) {
      ans[i] = vL;
    }
    return;
  }
  int mid = L + R, all = 0;
  mid /= 2;
  for (int i = 1; i <= N; i++) {
    all++;
    take++;
    was[arr[i]] = take;
    int now = 1;
    while (i < N) {
      if (was[arr[i + 1]] == take) {
        i++;
        continue;
      }
      if (now == mid) break;
      now++;
      was[arr[i + 1]] = take;
      i += 1;
    }
  }
  ans[mid] = all;
  f(L, mid - 1, ans[mid], vR);
  f(mid + 1, R, vL, ans[mid]);
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  f(1, N, 1, N);
  for (int i = 1; i <= N; i++) cout << ans[i] << " ";
  return 0;
}
