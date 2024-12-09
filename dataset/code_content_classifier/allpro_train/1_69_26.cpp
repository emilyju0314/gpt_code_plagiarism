#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int C[300000];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    C[a+b]++;
  }
  vector<int> ans;
  rep(i, 300000-1) {
    C[i+1] += C[i]/2;
    if (C[i]%2) ans.pb(i);
  }
  for (int x : ans) cout << x << " " << 0 << "\n";
  return 0;
}