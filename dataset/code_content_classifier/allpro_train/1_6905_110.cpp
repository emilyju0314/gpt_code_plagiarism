#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve(int n, int v, int w) {
  while(v != w) {
    if(v > w) {
      v = (v+n-2) / n;
    }else{
      w = (w+n-2) / n;
    }
  }
  cout << v << endl;
}

int main(){
  int n; cin >> n;
  int q; cin >> q;
  int v, w;
  for(int i=0; i<q; i++) {
    cin >> v >> w;
    if(n == 1) {
      cout << min(v, w) << endl;
      continue;
    }
    solve(n, v, w);
  }
  return 0;
}


// EOF
