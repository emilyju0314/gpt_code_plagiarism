#include <bits/stdc++.h>
using namespace std;
map<int, int> a;
pair<int, int> b[300000] = {};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int aa;
    scanf("%d", &aa);
    a[aa]++;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i].first);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i].second);
  }
  int ans_now = -1;
  for (int i = 0; i < m; ++i) {
    if (ans_now < a[b[i].first]) {
      ans_now = a[b[i].first];
    }
  }
  int final_ans = -1;
  int ans_nowmax = -1;
  for (int i = 0; i < m; ++i) {
    if (ans_now == a[b[i].first]) {
      if (ans_nowmax < a[b[i].second]) {
        ans_nowmax = a[b[i].second];
        final_ans = i + 1;
      }
    }
  }
  cout << final_ans << endl;
}
