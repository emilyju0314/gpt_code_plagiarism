#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001], b[2001], pos[2001], dest[2001];
int main(int argc, const char* argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    dest[b[i]] = i;
  }
  int total_steps = 0;
  vector<pair<int, int> > steps;
  for (int i = 1; i <= n; i++) {
    int cur = pos[b[i]];
    while (cur != i) {
      for (int j = i; j < cur; j++)
        if (dest[a[j]] >= cur) {
          swap(a[cur], a[j]);
          pos[a[cur]] = cur;
          pos[a[j]] = j;
          total_steps += cur - j;
          steps.push_back(make_pair(j, cur));
          cur = j;
          break;
        }
    }
  }
  cout << total_steps << endl;
  cout << steps.size() << endl;
  for (pair<int, int> p : steps) cout << p.first << ' ' << p.second << endl;
  return 0;
}
