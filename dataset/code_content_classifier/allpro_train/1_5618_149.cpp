#include <iostream>
#include <queue>
using namespace std;

const int INF = (1<<21);

class state{
public:
  int n,d;
  state(int n=0, int d=0):n(n),d(d){}
  bool operator < (const state &s) const {return d > s.d;}
};

int main(){
  int n,m;
  while(cin >> n >> m){
    int G[100][100];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) G[i][j] = INF;
    for(int i=0;i<m;i++){
      int a;
      cin >> a;
      if(a){
	int b,c,d;
	cin >> b >> c >> d;
	b--;
	c--;
	if(G[b][c] > d) G[b][c] = G[c][b] = d;
      }
      else{
	int b,c,d[100];
	bool f[100];
	priority_queue<state> Q;
	for(int j=0;j<n;j++) d[j] = INF, f[j] = false;
	cin >> b >> c;
	b--;
	c--;
	d[b] = 0;
	state u(b,0);
	Q.push(u);
	while(!Q.empty()){
	  u = Q.top();
	  Q.pop();
	  f[u.n] = true;
	  if(u.n == c) break;
	  for(int j=0;j<n;j++){
	    if(!f[j] && d[u.n] + G[u.n][j] < d[j]){
	      state v(j,d[u.n]+G[u.n][j]);
	      d[j] = v.d;
	      Q.push(v);
	    }
	  }
	}
	if(d[c] == INF) d[c] = -1;
	cout << d[c] << endl;
      }
    }
  }
  return 0;
}