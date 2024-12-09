#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int N, M;
int a[10];

pair<vector<int>,int> run() {
  vector<int> v(N), h(N, 0);
  for(int i = 0; i < N; ++i) v[i] = i;
  for(int i = 0; i < M; ++i) {
    swap(v[a[i]], v[a[i]+1]);
    int nh = max(h[a[i]], h[a[i]+1]) + 1;
    h[a[i]] = h[a[i]+1] = nh;
  }
  return make_pair(v, *max_element(h.begin(), h.end()));
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    cin >> a[i];
    --a[i];
  }
  pair<vector<int>,int> ans = run();
  sort(a, a+M);
  do {
    pair<vector<int>, int> p = run();
    if(p.first == ans.first) {
      ans.second = min(ans.second, p.second);
    }
  } while(next_permutation(a, a+M));
  cout << ans.second << endl;
  return 0;
}