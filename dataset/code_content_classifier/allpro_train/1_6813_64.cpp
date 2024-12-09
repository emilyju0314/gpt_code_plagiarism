#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
int n;
long long a[N];
vector<long long> pos[N];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= 1;
    pos[a[i]].push_back(i);
  }
  int ans = 0;
  while (1) {
    int ok = 1;
    for (int i = 0; ok && i < n - 1; i++) {
      int x = a[i];
      int y = a[i + 1];
      if (x == y) continue;
      set<int> S;
      S.insert(pos[x][0]);
      S.insert(pos[x][1]);
      S.insert(pos[y][0]);
      S.insert(pos[y][1]);
      int mn = *S.begin();
      int mx = *S.rbegin();
      if (mn == min(pos[y][0], pos[y][1]) && mx == max(pos[x][0], pos[x][1])) {
        ok = 0;
        ans++;
        swap(a[i], a[i + 1]);
        pos[x].clear();
        pos[y].clear();
        pos[y][0] = *S.begin();
        S.erase(S.begin());
        pos[y][1] = *S.begin();
        S.erase(S.begin());
        pos[x][0] = *S.begin();
        S.erase(S.begin());
        pos[x][1] = *S.begin();
        S.erase(S.begin());
      }
    }
    if (ok)
      for (int i = 0; ok && i < n - 1; i++) {
        int x = a[i];
        int y = a[i + 1];
        if (x == y) continue;
        set<int> S;
        S.insert(pos[x][0]);
        S.insert(pos[x][1]);
        S.insert(pos[y][0]);
        S.insert(pos[y][1]);
        int mn = *S.begin();
        int mx = *S.rbegin();
        if (mn == min(pos[x][0], pos[x][1]) &&
            mx == max(pos[x][0], pos[x][1])) {
          ok = 0;
          ans++;
          swap(a[i], a[i + 1]);
          pos[x].clear();
          pos[y].clear();
          pos[y][0] = *S.begin();
          S.erase(S.begin());
          pos[x][0] = *S.begin();
          S.erase(S.begin());
          pos[y][1] = *S.begin();
          S.erase(S.begin());
          pos[x][1] = *S.begin();
          S.erase(S.begin());
        }
      }
    if (ok) break;
  }
  cout << ans << endl;
  return 0;
}
