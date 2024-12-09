#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int main() {

  int N, M; cin >> N >> M;
  vector<int> v(N, inf);
  rep(i, M) {
    int x; cin >> x; x--;
    v[x] = 0;
  }

  REP(i, 1, N) {
    v[i] = min(v[i], v[i-1] + 1);
  }

  for(int i=N-2; i>=0; i--) {
    v[i] = min(v[i], v[i+1] + 1);
  }

  cout << *max_element(all(v)) << endl;

  return 0;
}