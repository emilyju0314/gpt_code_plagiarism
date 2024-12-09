#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, arr[N], tmp[N];
int d[N], t[N], s = 0;
pair<int, int> arr2[N];
set<int> st;
set<int>::iterator it;
bool check(int mid) {
  int one = s * 2 - mid;
  if (one > mid) return false;
  for (int i = 0; i < n; i++) tmp[i] = arr[i];
  st.clear();
  int j = 0, cur = 0;
  while (j < m && arr2[j].first > mid) j++;
  for (int i = mid; i > 0; i--) {
    while (j < m && arr2[j].first >= i) {
      if (tmp[arr2[j].second] != 0) st.insert(arr2[j].second);
      j++;
    }
    if ((int)st.size() == 0) continue;
    it = st.begin();
    tmp[*it]--;
    cur++;
    if (tmp[*it] == 0) st.erase(it);
  }
  if (cur >= one) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    s += arr[i];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &arr2[i].first, &arr2[i].second);
    arr2[i].second--;
  }
  sort(arr2, arr2 + m);
  reverse(arr2, arr2 + m);
  int low = 1, high = s * 2, res = s * 2, mid;
  while (high >= low) {
    mid = (low + high) / 2;
    if (check(mid))
      res = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  cout << res << endl;
  return 0;
}
