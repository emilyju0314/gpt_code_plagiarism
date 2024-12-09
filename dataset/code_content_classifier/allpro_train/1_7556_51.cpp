#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a:x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD=1e9+7;
template<class T> using pqg=priority_queue<T, vector<T>, greater<T>>;

int n, M;
ll dp[401][401];
ll C[401][401];
ll pw[401];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);

  cin >> n >> M;
  rep(i, 0, n) C[i][0]=1;
  rep(i, 1, n){
    rep(j, 1, i){
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
    }
  }
  pw[0]=1;
  rep(i, 1, n){
    pw[i]=(pw[i-1]*2)%M;
  }

  dp[0][0]=1;
  dp[1][1]=1;
  dp[2][2]=2;
  rep(i, 3, n){
    rep(j, 1, i){
      for(int k=1; k<=min(j, i-2); k++){
        if(k<=i-2) dp[i][j]+=((pw[k-1]*dp[i-k-1][j-k])%M*C[j][k])%M;
      }
      if(j==i) dp[i][j]+=pw[i-1];
      dp[i][j]%=M;
      // cout << "dp[" << i << "][" << j << "] " << dp[i][j] << nl;
    }
  }

  ll ans=0;
  rep(i, 1, n) ans=(ans+dp[n][i])%M;
  cout << ans;
}