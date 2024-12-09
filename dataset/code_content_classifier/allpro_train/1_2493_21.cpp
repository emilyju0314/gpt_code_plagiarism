#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100005; 
vector<pair<int, int>> edges[NMAX];
int ans[NMAX];
 
void dfs(int i, int par, int pc){
  int c = 1;
  for(auto p : edges[i]){
      int j = p.first, idx = p.second;
      if(j == par) continue;
      if(c == pc) c++;
      ans[idx] = c;
      dfs(j, i, c);
      c++;
    }
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N-1; i++){
      int a, b;
      cin >> a >> b;
      a--; b--;
      edges[a].emplace_back(b, i);
      edges[b].emplace_back(a, i);
    }
    dfs(0, -1, -1);
    cout << *max_element(ans, ans+N-1) << endl;
    for(int i=0; i<N-1; i++) cout << ans[i] << endl;
    return 0;
}
