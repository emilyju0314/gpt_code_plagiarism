#include <bits/stdc++.h>
using namespace std;
int times[100001];
int ans[100001];
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> times[i];
  }
  priority_queue<int> tmp;
  priority_queue<int> pq;
  int tmpSum = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    tmpSum = sum;
    tmp = pq;
    while (!pq.empty() && sum + times[i] > m) {
      int dif = pq.top();
      pq.pop();
      sum -= dif;
    }
    ans[i] = (int)(i - pq.size());
    pq = tmp;
    sum = tmpSum;
    sum += times[i];
    pq.push(times[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
