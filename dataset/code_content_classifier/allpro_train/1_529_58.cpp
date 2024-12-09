#include <bits/stdc++.h>
using namespace std;
struct A {
  long long val;
  long long time;
};
bool cmp(A a, A b) { return a.val < b.val; }
vector<long long> cost[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    vector<A> arr;
    for (int i = 0; i < n; i++) {
      A a;
      cin >> a.val;
      arr.push_back(a);
    }
    for (int i = 0; i < n; i++) {
      cin >> arr[i].time;
    }
    sort(arr.begin(), arr.end(), cmp);
    priority_queue<pair<long long, long long> > pq;
    long long ans = 0;
    long long cnt = 0;
    long long left;
    vector<long long> tmp;
    for (int i = 0; i < n; i++) {
      long long left = arr[i].val;
      if ((i + 1) < n && arr[i + 1].val == left) {
        long long tot = 0;
        while ((i) < n && arr[i].val == left) {
          i++;
          tot++;
        }
        i--;
        cnt += (tot - 1LL);
      }
      tmp.push_back(left);
      left++;
      while (cnt > 0) {
        if ((i + 1) < n && arr[i + 1].val > left) {
          tmp.push_back(left);
          left++;
          cnt--;
        } else if ((i + 1) < n && arr[i + 1].val <= left) {
          break;
        } else {
          tmp.push_back(left);
          left++;
          cnt--;
        }
      }
    }
    int j = 0;
    for (int i = 0; i < tmp.size(); i++) {
      while (j < n && arr[j].val == tmp[i]) {
        pq.push(make_pair(arr[j].time, arr[j].val));
        j++;
      }
      long long p1 = (tmp[i] - pq.top().second);
      long long p2 = pq.top().first;
      ans += (p1 * p2);
      pq.pop();
    }
    cout << ans << "\n";
  }
  return 0;
}
