#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589
 
 
#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};
 
//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL
 
struct Edge {
	ll from, to;
	ll w;
};
typedef vector<vector<Edge>> Graph;
 
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}
int main(){
  int n;
  cin >> n;

  Graph g(n);

  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--,b--;
    g[a].push_back({a,b});
    g[b].push_back({b,a});
  }

  vector<int> dp(n);

  function<int(int,int)> dfs1 = [&](int par , int cur){
    int Max = 1;
    for(auto itr : g[cur]){
      if(itr.to == par) continue;
      Max = max(Max,1 + dfs1(cur,itr.to));
    }

    return dp[cur] = Max;
  };

  dfs1(0,0);

  vector<int> ok(n + 1);

  function<void(int,int,int)> dfs2 = [&](int par, int cur, int oya){
    multiset<int, greater<int>> cand;
    cand.insert(oya);

    for(auto itr : g[cur]){
      if(itr.to == par) continue;
      cand.insert(dp[itr.to]);
    }

    if(cand.size() - (oya == 0) >= 3){
      array<int,3> chu = {*cand.begin(),*(++cand.begin()),*(++(++cand.begin())) };
      REP(i,3){
        vector<int> ca;
        REP(j,3){
          if(i != j)
            ca.push_back(chu[j]);
        }
        int Ma = min(n,chu[i] + min(ca[0], ca[1]));
        if(Ma % 2 == 0 && chu[i] == Ma / 2){
          if(Ma > 0)
            ok[Ma - 1] = 1;
        }
        else
          ok[Ma] = 1;
      }
    }
    
    for(auto itr : g[cur]){
      if(itr.to == par) continue;
      int nexOya;
      cand.erase(cand.find(dp[itr.to]));
      nexOya = *cand.begin();
      dfs2(cur,itr.to, 1 + nexOya);
      cand.insert(dp[itr.to]);
    }
  };

  dfs2(0,0,0);

  int al = 0;
  for(int i = n; 1 <= i; i--){
    al |= ok[i];
    ok[i] = al;
  }

  rep(i,1,n + 1){
    if(i <= 2) ok[i] = 0;
    printf("%d", 1-ok[i]);
  }
  cout << endl;
}
