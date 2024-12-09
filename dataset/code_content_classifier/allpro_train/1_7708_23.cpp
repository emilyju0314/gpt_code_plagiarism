#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 15
#define INF 1000000

int V,E,D[MAX_V][MAX_V],all_d;
vector<int> G[MAX_V][MAX_V];

int solve() {
  for (int i=0;i<V;++i) {
    for (int j=0;j<V;++j) {
      for (int k=0;k<V;++k) {
        D[j][k] = min(D[j][k], D[j][i]+D[i][k]);
      }
    }
  }
  // for (int j=0;j<V;++j) {
  //   for (int k=0;k<V;++k) {
  //     cout<<"D"<<" "<<j<<" "<<k<<" "<<D[j][k]<<endl;
  //   }
  // }

  vector<int> odd_v;
  for (int i=0;i<V;++i) {
    int order = 0;
    for (int j=0;j<V;++j) {
      order += G[i][j].size();
    }
    if (order%2) {
      odd_v.push_back(i);
    }
  }
  // for (int i=0;i<odd_v.size();++i) {
  //   cout<<odd_v[i]<<endl;
  // }

  int odd_n = odd_v.size();
  int dp[1<<odd_n];
  for (int i=0;i<(1<<odd_n);++i) {
    dp[i] = INF;
  }
  dp[0] = 0;
  for (int s=0;s<(1<<odd_n);++s) {
    for (int i=0;i<odd_n&&!(s>>i&1);++i) {
      for (int j=0;j<odd_n;++j) {
        if (i!=j && ~s>>j&1) {
          dp[s|(1<<i)|(1<<j)] = min(dp[s|(1<<i)|(1<<j)],dp[s]+D[odd_v[i]][odd_v[j]]);
        }
      }
    }
    // cout<<dp[s]<<endl;
  }

  return all_d + dp[(1<<odd_n)-1];
}

int main() {
  for (int i=0;i<MAX_V;++i) {
    for (int j=0;j<MAX_V;++j) {
      D[i][j] = (i==j)?0:INF;
    }
  }
  cin>>V>>E;
  for (int i=0;i<E;++i) {
    int s,t,d;
    cin>>s>>t>>d;
    all_d += d;
    G[s][t].push_back(d);
    G[t][s].push_back(d);
    D[s][t] = min(D[s][t], d);
    D[t][s] = min(D[t][s], d);
  }
  cout<<solve()<<endl;
  return 0;
}
