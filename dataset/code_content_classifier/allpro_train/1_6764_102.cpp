#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int arr[N + 100];
long long ans[N + 100], grt[N + 100], les[N + 100], cnt[N + 100];
long long grtn[N + 100], lesn[N + 100];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", arr + i);
  }
  for (int i = 1; i < m; i++) {
    ans[1] += abs(arr[i] - arr[i + 1]);
    if (arr[i] == arr[i + 1]) continue;
    grtn[min(arr[i], arr[i + 1])]++;
    grt[min(arr[i], arr[i + 1])] += abs(arr[i] - arr[i + 1]);
    lesn[max(arr[i], arr[i + 1])]++;
    les[max(arr[i], arr[i + 1])] += abs(arr[i] - arr[i + 1]);
    cnt[max(arr[i], arr[i + 1])] += min(arr[i], arr[i + 1]);
  }
  long long t1 = grt[1], t2 = 0, tn = grtn[1];
  for (int i = n; i >= 3; i--) {
    t2 += grt[i];
  }
  for (int i = 2; i <= n; i++) {
    ans[i] = t2;
    ans[i] += cnt[i];
    t1 -= les[i];
    tn -= lesn[i];
    ans[i] += (t1 - tn);
    ans[i] += grt[i];
    ans[i] += grtn[i] * (i - 1);
    t1 += grt[i];
    tn += grtn[i];
    t2 -= grt[i + 1];
    t2 += les[i];
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", ans[i]);
  }
}
