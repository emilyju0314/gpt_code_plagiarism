#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

typedef pair<int, int> Pi;
typedef tuple<int, int, int> Ti;
typedef vector<int> vint;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int H, N, P, M, K;
vint line;

vector<vint> amida;

double dp[2][128][128];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> H >> N >> P >> M >> K;
  --P;

  resz(line, H, -1);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    line[H-a] = --b;
  }

  memset(dp, 0, sizeof(dp));

  double (*curr)[128] = dp[0];
  double (*next)[128] = dp[1];

  curr[0][P] = 1;

  rep(i, H) {
    rep(k, K+1) rep(j, N) next[k][j] = 0;
    if(~line[i]) { // ???????????????????????????????????????????¢???????swap
      rep(k, K+1) rep(j, N) next[k][j] = curr[k][j];
      rep(k, K+1) {
	next[k][line[i]] = curr[k][line[i]+1];
	next[k][line[i]+1] = curr[k][line[i]];
      }
      swap(curr, next);
      continue;
    }
    int cnt = 0; // ??????????????????????±??????£???????????????????????°
    reps(j, i, H) if(line[j] == -1) cnt++;
    if(cnt == 0) {
      rep(k, K+1) rep(j, N) next[k][j] += curr[k][j];
      continue;
    }
    rep(k, K+1) {
      double p = (double)(K-k)/cnt; // ??????cnt?????????????????????(K-k)????????¬???????????°??????
      rep(j, N) next[k][j] += curr[k][j]*(1-p); // ??????i????????°??????????????°??????????????????
    }
    rep(k, K) {
      double p = (double)(K-k)/cnt; // ??????cnt?????????????????????(K-k)????????¬???????????°??????
      rep(j, N) {
	double x = 0;
	if(j > 0) {
	  next[k+1][j-1] += curr[k][j]*p/(N-1); // ??????i????????°????????????????£?j-1&j????????????????¢???????p*1/(N-1)
	  x += 1.0/(N-1);
	}
	if(j < N-1) {
	  next[k+1][j+1] += curr[k][j]*p/(N-1); // ?£?j&j+1
	  x += 1.0/(N-1);
	}
	next[k+1][j] += curr[k][j]*p*(1-x); // ??????i????????°?????????(1-x)????¢??????§?£?j????????¢??????????????????????????????
      }
    }
    swap(curr, next);
  }
  /*
  rep(i, H+1) {
    rep(k, K+1) {
      rep(j, N) cout<<dp[i][k][j]<<" ";
      cout<<endl;
    }
    cout<<endl;
  }
  */
  double ans = 0;
  rep(i, N) chmax(ans, curr[K][i]);
  cout << ans << endl;

  return 0;
}