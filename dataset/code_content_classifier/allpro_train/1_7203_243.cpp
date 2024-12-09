#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M, N;
  cin >> N >> M;
  int a[M];
  long long int sum = 0;
  priority_queue<pair<int, int> > pq;
  for (int(i) = 0; (i) < (M); (i)++) {
    cin >> a[i];
    sum += a[i];
    pq.push(make_pair(a[i], N - i));
  }
  if (sum < N) {
    cout << -1 << endl;
    return 0;
  }
  int cur = 0;
  long long int rem = sum;
  vector<int> v(M, 0);
  for (int(i) = 0; (i) < (M); (i)++) {
    int care = a[i];
    int index = i;
    pq.pop();
    if (cur <= (N - care)) {
      int reduce = ((care - 1 > sum - N) ? sum - N : care - 1);
      v[index] = (cur + 1);
      cur += (care - reduce);
      sum -= reduce;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  for (auto i : v) cout << i << " ";
  cout << endl;
  return 0;
}
