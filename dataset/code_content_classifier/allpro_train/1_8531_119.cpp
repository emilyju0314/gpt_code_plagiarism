#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
char str[maxn];
int a[maxn][maxn], lef[maxn][maxn], rig[maxn][maxn];
int en[maxn], fen[maxn];
vector<pair<int, pair<int, int> > > q;
vector<pair<int, int> > nums;
inline void add(int p, int val) {
  for (p++; p < maxn; p += p & -p) fen[p] += val;
}
inline int get(int p) {
  int ret = 0;
  for (; p; p -= p & -p) ret += fen[p];
  return ret;
}
int solve(int n, int I, int J) {
  sort(q.begin(), q.end());
  reverse(q.begin(), q.end());
  for (int i = 0; i < n; i++) nums.push_back({en[i], i});
  sort(nums.begin(), nums.end(), greater<pair<int, int> >());
  int cur = 0, ans = 0;
  for (int i = 0; i < q.size(); i++) {
    while (cur < n && nums[cur].first > q[i].first) {
      add(nums[cur].second, 1);
      cur++;
    }
    ans += get(q[i].second.second) - get(q[i].second.first);
  }
  for (; cur--;) add(nums[cur].second, -1);
  q.clear();
  nums.clear();
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    for (int j = 0; j < m; j++) a[i][j] = (str[j] == 'z');
  }
  n = max(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      lef[i][j] = (!j ? a[i][j] : (!a[i][j] ? 0 : 1 + lef[i][j - 1]));
  for (int i = 0; i < n; i++)
    for (int j = n; j--;)
      rig[i][j] = (j == n - 1 ? a[i][j] : (!a[i][j] ? 0 : 1 + rig[i][j + 1]));
  long long Ans = 0;
  vector<pair<int, int> > v;
  for (int d = 0; d <= (n - 1) * 2; d++) {
    v.clear();
    for (int i = 0; i < n; i++) {
      int j = d - i;
      if (j < 0 || j >= n) continue;
      v.push_back({i, j});
    }
    for (int i = 0; i < v.size(); i++) {
      if (a[v[i].first][v[i].second] &&
          (!i || !a[v[i - 1].first][v[i - 1].second])) {
        int lst, ind = 0, N = 0;
        for (int j = i; j < v.size() && a[v[j].first][v[j].second]; j++)
          lst = j, N++;
        for (int j = i; j <= lst; j++) {
          en[ind] = min(ind + lef[v[j].first][v[j].second], N);
          ind++;
        }
        for (int j = lst; j >= i; j--) {
          ind--;
          int L = max(0, ind - rig[v[j].first][v[j].second] + 1);
          q.push_back({ind, {L, ind + 1}});
        }
        Ans += solve(N, v[i].first, v[i].second);
      }
    }
  }
  cout << Ans << endl;
}
