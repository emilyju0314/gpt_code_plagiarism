#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

vector<vector<int> > sum10;
vector<int> as;

void dfs(vector<int> v, int now, int sum) {
  if (sum == 10) {
    sum10.push_back(v);
    return;
  }
  if (now == as.size()) return;
  dfs(v,now+1,sum);
  if (sum + as[now] <= 10) {
    v.push_back(now);
    dfs(v,now,sum+as[now]);
  }
}

map<vector<int> , int> mp[50];

int solve(int now, vector<int> v) {
  if (now == sum10.size()) return 0;
  if (mp[now].count(v)) return mp[now][v];

  int a;
  int &r = a;
  if (now<sum10.size()-5) r = mp[now][v];
  int res = 0;
  REP(i,100) {
    bool dame = 0;
    res = max(res, solve(now+1, v) + i);
    FOR(it, sum10[now]) {
      if (v[*it]-- == 0) dame = 1;
    }
    if(dame) break;
  }
  if (now<sum10.size()-5) return r = res;
  return res;
}

int a[10];

int main() {
  // REP(i,9) as.push_back(i+1);
  // vector<int> t;
  // dfs(t,0,0);
  // FOR(it, sum10) {
  //   FOR(jt, *it) cout << *jt << " ";
  //   cout << endl;
  // }
  int n;
  while(cin>>n,n) {
    int ans = 0;
    memset(a,0,sizeof(a));
    REP(i,n) {
      int b;cin >> b;
      if (b >= 10) {
        if (b == 10) ans++;
      } else {
        a[b]++;
      }
    }
    for (int i=1; i<=4; ++i) {
      int j = 10-i;
      int m = min(a[i], a[j]);
      a[i] -= m;
      a[j] -= m;
      ans += m;
    }
    ans += a[5] / 2;
    a[5] -= a[5]/2*2;
    vector<int> v;
    as.clear();
    REP(i,10) if (a[i]) {
      as.push_back(i);
      v.push_back(a[i]);
    }
    sum10.clear();
    vector<int> t;
    dfs(t,0,0);
    REP(i,sum10.size()) mp[i].clear();
    ans += solve(0,v);
    cout << ans << endl;
  }
}