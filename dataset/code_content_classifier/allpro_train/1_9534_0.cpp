#include <bits/stdc++.h>
using namespace std;
int L[1000], R[1000];
int ans[1000];
vector<int> v;
int n;
int check(int lo);
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", L + i);
  for (int i = 0; i < n; i++) scanf("%d", R + i);
  for (int i = 0; i < n; i++) v.push_back(L[i] + R[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++)
    ans[i] = n - (lower_bound(v.begin(), v.end(), L[i] + R[i]) - v.begin());
  for (int i = 0; i < n; i++) {
    if (check(i) == 0 || ans[i] < 0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}
int check(int lo) {
  int ll = 0, rr = 0;
  for (int i = 0; i < lo; i++) ll += (ans[i] > ans[lo]);
  for (int i = lo + 1; i < n; i++) rr += (ans[i] > ans[lo]);
  return (ll == L[lo]) && (rr == R[lo]);
}
