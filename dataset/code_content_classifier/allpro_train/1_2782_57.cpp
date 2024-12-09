#include <bits/stdc++.h>
using namespace std;
int test = 0;
const int MAXN = 200009;
const long long MOD = 998244353;
class {
 public:
  long long n, p, ans[MAXN], in[MAXN];
  void solve() {
    cin >> n >> p;
    priority_queue<pair<int, int> > Q;
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      Q.push({-t, -i});
    }
    long long T = 0;
    priority_queue<int> wait, quep;
    queue<int> que;
    while (Q.size() + wait.size() + que.size()) {
      if (que.empty()) {
        if (!wait.empty()) {
          que.push(-wait.top());
          in[-wait.top()] = true;
          quep.push(wait.top());
          wait.pop();
        } else {
          T = -Q.top().first;
          que.push(-Q.top().second);
          in[-Q.top().second] = true;
          quep.push(Q.top().second);
          Q.pop();
          while (!Q.empty() && -Q.top().first <= T)
            wait.push(Q.top().second), Q.pop();
        }
      }
      int Min = n + 1;
      while (!quep.empty()) {
        if (!in[-quep.top()])
          quep.pop();
        else {
          Min = -quep.top();
          break;
        }
      }
      while (!Q.empty() && -Q.top().first < T + p) {
        if (-Q.top().second < Min) {
          que.push(-Q.top().second);
          in[-Q.top().second] = true;
          quep.push(Q.top().second);
          Min = -Q.top().second;
        } else {
          wait.push(Q.top().second);
        }
        Q.pop();
      }
      T += p;
      ans[que.front()] = T;
      in[que.front()] = false;
      que.pop();
      Min = n + 1;
      while (!quep.empty()) {
        if (!in[-quep.top()])
          quep.pop();
        else {
          Min = -quep.top();
          break;
        }
      }
      while (!Q.empty() && -Q.top().first <= T) {
        wait.push(Q.top().second);
        Q.pop();
      }
      if (!wait.empty() && -wait.top() < Min) {
        que.push(-wait.top());
        quep.push(wait.top());
        in[-wait.top()] = true;
        wait.pop();
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
