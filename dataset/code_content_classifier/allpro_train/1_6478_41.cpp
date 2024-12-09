#include<iostream>
#include<vector>
#include<cassert>
#include<set>
using namespace std;
static const int MAX = 100;

vector<int> G[MAX+1];
vector<int> R[MAX+1];
vector<int> ans;
bool V[MAX+1];
int W[MAX+1];

int N, M, cnt;

void dfs(int u){
  V[u] = true;
  cnt++;

  for ( int i = 0; i < G[u].size(); i++ ){
    int v = G[u][i];
    if ( !V[v] ) dfs(v);
  }
  ans.push_back(u);
}

int main(){
  cin >> N >> M;

  for ( int i = 1; i <= N; i++ ) {
    V[i] = false;
    W[i] = -1;
  }

  int s, t;
  for ( int i = 0; i < M; i++ ){
    cin >> s >> t;
    W[s] = t;
    G[t].push_back(s);
    R[s].push_back(t);
  }

  cnt = 0;
  dfs(2);
  for ( int i = 0; i < N; i++ ) cout << ans[i] << endl;
}