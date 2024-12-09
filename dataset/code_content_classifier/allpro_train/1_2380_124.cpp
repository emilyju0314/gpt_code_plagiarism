#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, w, vis[maxn][3];
long long minw;
long long ans, ans1, ans2, ans3, ans4;
struct node {
  long long t1, t2;
} a[maxn];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    q1, q2, q3;
priority_queue<pair<long long, int> > q4, q5;
int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].t1, &a[i].t2);
    q1.push(make_pair(a[i].t1, i));
    q2.push(make_pair(a[i].t2, i));
    vis[i][0] = 1;
  }
  for (int i = 1; i <= w; i++) {
    ans1 = ans2 = ans3 = ans4 = 0x3f3f3f3f3f3f;
    while (!q1.empty() && !vis[q1.top().second][0]) q1.pop();
    while (!q2.empty() && !vis[q2.top().second][0]) q2.pop();
    while (!q3.empty() && !vis[q3.top().second][1]) q3.pop();
    while (!q4.empty() && !vis[q4.top().second][1]) q4.pop();
    while (!q5.empty() && !vis[q5.top().second][2]) q5.pop();
    if (!q1.empty()) ans1 = q1.top().first;
    if (!q3.empty()) ans2 = q3.top().first;
    if (!q2.empty() && !q4.empty()) ans3 = q2.top().first - q4.top().first;
    if (!q5.empty() && !q2.empty()) ans4 = q2.top().first - q5.top().first;
    minw = min(min(ans1, ans2), min(ans3, ans4));
    ans += minw;
    if (minw == ans1) {
      int id = q1.top().second;
      q1.pop();
      vis[id][0] = 0;
      vis[id][1] = 1;
      q3.push(make_pair(a[id].t2 - a[id].t1, id));
      q4.push(make_pair(a[id].t1, id));
      continue;
    }
    if (minw == ans2) {
      int id = q3.top().second;
      q3.pop();
      vis[id][1] = 0;
      vis[id][2] = 1;
      q5.push(make_pair(a[id].t2 - a[id].t1, id));
      continue;
    }
    if (minw == ans3) {
      int id1 = q2.top().second;
      int id2 = q4.top().second;
      q2.pop();
      q4.pop();
      vis[id1][0] = 0;
      vis[id1][2] = 1;
      vis[id2][1] = 0;
      vis[id2][0] = 1;
      q5.push(make_pair(a[id1].t2 - a[id1].t1, id1));
      q1.push(make_pair(a[id2].t1, id2));
      q2.push(make_pair(a[id2].t2, id2));
      continue;
    }
    if (minw == ans4) {
      int id1 = q2.top().second;
      int id2 = q5.top().second;
      q2.pop();
      q5.pop();
      vis[id1][0] = 0;
      vis[id1][2] = 1;
      vis[id2][2] = 0;
      vis[id2][1] = 1;
      q5.push(make_pair(a[id1].t2 - a[id1].t1, id1));
      q3.push(make_pair(a[id2].t2 - a[id2].t1, id2));
      q4.push(make_pair(a[id2].t1, id2));
      continue;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    if (vis[i][0])
      printf("0");
    else if (vis[i][1])
      printf("1");
    else if (vis[i][2])
      printf("2");
  }
  return 0;
}
