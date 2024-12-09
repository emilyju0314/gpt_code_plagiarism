#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 202;

using vint = vector<int>;

vint G[MAX_N];
bool H[MAX_N][MAX_N];

int col[MAX_N];
bool dfs(int u, int c) {
 col[u] = c;
  for(int v : G[u]) {
    if(col[v] == c) assert(false);//return false;
    if(col[v] == 0) dfs(v, -c);
  }
  return true;
}

int main() {
  int n;
  while(cin >> n, n) {
    for(int i = 0; i < MAX_N; ++i) G[i].clear();
    memset(H, false, sizeof(H));
    memset(col, 0, sizeof(col));
    map<string, int> mp;
    int sz = 0;
    for(int i = 0; i < n; ++i) {
      string cross;
      cin >> cross;
      int idx = cross.find('-');
      string s = cross.substr(0, idx);
      string t = cross.substr(idx+1);
      if(!mp.count(s)) mp[s] = sz++;
      if(!mp.count(t)) mp[t] = sz++;
      int u = mp[s], v = mp[t];
      G[u].push_back(v);
      G[v].push_back(u);
      H[u][v] = true;
    }
    cout << sz << endl;
    for(int i = 0; i < sz; ++i) {
      if(!col[i]) dfs(i, 1);
    }
    for(int i = 0; i < sz; ++i) {
      for(int j = i+1; j < sz; ++j) {
	bool c = false;
	bool d = true;
	bool e = true;
	for(int k = 0; k < sz; ++k) {
	  if(i == k || j == k) continue;
	  if(H[i][k] && H[j][k]) c = true;
	  if(H[k][i] && H[k][j]) c = true;
	  if(H[k][i] && H[j][k]) d = false;
	  if(H[i][k] && H[k][j]) e = false;
	}
	H[i][j] |= (c&&d&&e);
	H[j][i] |= (c&&d&&e);
      }
    }
    for(int i = 0; i < sz; ++i) {
      for(int j = 0; j < sz; ++j) {
	for(int k = 0; k < sz; ++k) {
	  H[j][k] |= H[j][i]&H[i][k];
	}
      }
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
      string cross;
      cin >> cross;
      int idx = cross.find('-');
      string s = cross.substr(0, idx);
      string t = cross.substr(idx+1);
      if(!mp.count(s)) {
	cout << "NO" << endl;
	continue;
      }
      if(!mp.count(t)) {
	cout << "NO" << endl;
	continue;      
      }
      int u = mp[s], v = mp[t];
      //cout<<col[u]<<" "<<col[v]<<endl;      
      if(col[u] == col[v]) {
	cout << "NO" << endl;
	continue;
      }
      if(H[u][v]) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}

