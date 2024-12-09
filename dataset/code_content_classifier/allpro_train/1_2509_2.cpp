#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int N, X;
int sr, sc, tr, tc;
int ar[101], ac[101];
int br[101], bc[101];
vint R; // compress
map<int, int> mp; // uncompress
set< pair<pint, pint> > st; // non-exist edge

double base;

double distance(int ar, int br) {
  return (ar == br ? (R[ar]+1)*base : abs(R[ar] - R[br]));
}

double mincost[808][101];

using State = tuple<double, int, int>;

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

double dijkstra() {
  priority_queue<State, vector<State>, greater<State> > que;
  fill(mincost[0], mincost[808], DBL_MAX/2);
  que.emplace(0, sr, sc);
  mincost[sr][sc] = 0;
  while(!que.empty()) {
    double cost; int r, c;
    tie(cost, r, c) = que.top(); que.pop();
    if(mincost[r][c] < cost) continue;
    if(r == tr && c == tc) return cost;
    rep(i, 4) {
      int nr = r + dr[i], nc = (c+dc[i]+N)%N;
      if(nr < 0 || R.size() <= nr) continue;
      auto u = make_pair(r, c);
      auto v = make_pair(nr, nc);
      if(st.count(make_pair(u, v))) continue;
      double dist = cost + distance(r, nr);
      if(dist < mincost[nr][nc]) {
	mincost[nr][nc] = dist;
	que.emplace(dist, nr, nc);
      }
    }
  }
  return -1;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  while(cin >> N >> X, N) {
    cin >> sr >> sc >> tr >> tc;
    --sr, --sc, --tr, --tc;
    R.clear();
    R.push_back(0);
    R.push_back(sr);
    R.push_back(tr);
    rep(i, X) {
      cin >> ar[i] >> ac[i] >> br[i] >> bc[i];
      --ar[i], --ac[i], --br[i], --bc[i];
      if(ar[i]) R.push_back(ar[i]-1);
      R.push_back(ar[i]);
      R.push_back(ar[i]+1);
      if(br[i]) R.push_back(br[i]-1);
      R.push_back(br[i]);
      R.push_back(br[i]+1);
    }
    sort(all(R));
    R.erase(unique(all(R)), R.end());
    mp.clear();
    st.clear();
    rep(i, R.size()) mp[R[i]] = i;
    sr = mp[sr], tr = mp[tr];
    rep(i, X) {
      ar[i] = mp[ar[i]], br[i] = mp[br[i]];
      auto u = make_pair(ar[i], ac[i]);
      auto v = make_pair(br[i], bc[i]);
      st.emplace(u, v);
      st.emplace(v, u);
    }
    base = sqrt(2.0-2.0*cos(2.0*acos(-1)/(double)N));
    cout << dijkstra() << endl;
  }

  return 0;
}