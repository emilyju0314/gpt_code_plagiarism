#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define Rep(i, N) for(int i = 0; i < N; i++)
#define pb push_back
#define LLINF 1LL << 60
#define INF 1 << 28
#define F first
#define S second
typedef pair<int, int> Pi;
typedef vector<int> vint;

inline void chmax(int &a, int b) { a = max(a, b); }
inline void chmin(int &a, int b) { a = min(a, b); }

int N, M;
int val[100005];
int A, B;
vint bs, D;

int dfs(int v, int X) {
  if(v < N) {
    if(val[v] == LLINF) {
      return 1;
    } else {
      if(val[v] >= X) return 0;
      else return LLINF;
    }
  }
  
  vint s;
  for(int i = (v - N) * 3; i < (v - N) * 3 + 3; i++) s.pb(dfs(i, X));
  sort(s.begin(), s.end());
  return min(s[0] + s[1], LLINF);
}
  

signed main()
{
  
  cin >> N >> M;
  fill_n(val, 100005, LLINF);
  
  Rep(i, M) {
    cin >> A >> B; B--;
    val[B] = A;
    bs.pb(A);
  }

  Rep(i, N - M) {
    cin >> A;
    bs.pb(A); D.pb(A);
  }
  
  sort(bs.begin(), bs.end());

  int l = 0, r = N;
  while(l + 1 < r) {
    int m = (l + r) / 2;
    int cnt = 0, X = bs[m];
    Rep(i, D.size()) if(D[i] >= X) cnt++;
    if(dfs(N + N / 2 - 1, X) <= cnt) l = m;
    else r = m;
  }

  cout << bs[l] << endl;
  return 0;
}