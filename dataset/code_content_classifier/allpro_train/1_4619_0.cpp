#include <bits/stdc++.h>
using namespace std;
struct BOX {
  long long len, num;
} box[100005];
bool cmp(BOX a, BOX b) { return a.len < b.len; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> box[i].len >> box[i].num;
  sort(box, box + n, cmp);
  for (int i = 0; i < n - 1; i++) {
    if (2 * box[i + 1].len - 2 * box[i].len < 32) {
      int t = ceil(box[i].num * 1.0 /
                   ((1 << (2 * box[i + 1].len - 2 * box[i].len)))) -
              box[i + 1].num;
      if (t > 0) box[i + 1].num += t;
    }
  }
  long long t = box[n - 1].num;
  int i;
  for (i = 1;; i++) {
    if (1 << (2 * i) >= t) break;
  }
  cout << i + box[n - 1].len << endl;
  return 0;
}
