#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define range(x,l,r) (l<=x && x<r)
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> tri;

int w,h;
int g[20][20];
int rem[20][20];
vector<tri> carpet[20][20];
int depth;

void search(int d){
  if(d==depth)return;

  vector<tri> priority;
  rep(i,h)rep(j,w){
    if(rem[i][j]){
      priority.push_back(tri(pii(carpet[i][j].size(),i),j));
    }
  }

  if(priority.size()==0){
    depth = d;
    return;
  }

  int y = priority[0].fs.sc, x = priority[0].sc;

  rep(k,carpet[y][x].size()){
    tri t = carpet[y][x][k];
    
    int tmp[20][20];
    for(int i=t.fs.fs;i<t.fs.fs+t.sc;i++){
      for(int j=t.fs.sc;j<t.fs.sc+t.sc;j++){
	tmp[i][j] = rem[i][j];
      }
    }

    for(int i=t.fs.fs;i<t.fs.fs+t.sc;i++){
      for(int j=t.fs.sc;j<t.fs.sc+t.sc;j++){
	rem[i][j] = 0;
      }
    }
    
    search(d+1);

    for(int i=t.fs.fs;i<t.fs.fs+t.sc;i++){
      for(int j=t.fs.sc;j<t.fs.sc+t.sc;j++){
	rem[i][j] = tmp[i][j];
      }
    }
    if(depth == d+1)return;
  }
}

int main(){
  while(cin >> w >> h, w){
    memset(g,0,sizeof(g));
    rep(i,h)rep(j,w){
      cin >> g[i][j];
      rem[i][j] = g[i][j];
      carpet[i][j].clear();
    }

    vector<tri> c;
    rep(i,h)rep(j,w){
      int k = 0;
      while(true){
	if(!range(i+k,0,h) || !range(j+k,0,w))break;
	int f = 1;
	for(int y=i;y<=i+k;y++)f &= g[y][j+k];
	for(int x=j;x<=j+k;x++)f &= g[i+k][x];
	if(!f)break;
	k++;
      }
      if(k)c.push_back( tri(pii(i,j), k) );
    }
    
    rep(i,c.size()){
      bool f = false;
      rep(j,c.size()){
	if(i==j)continue;
	if( range(c[i].fs.fs, c[j].fs.fs, c[j].fs.fs + c[j].sc) &&
	    range(c[i].fs.fs + c[i].sc, c[j].fs.fs, c[j].fs.fs + c[j].sc+1) &&
	    range(c[i].fs.sc, c[j].fs.sc, c[j].fs.sc + c[j].sc) &&
	    range(c[i].fs.sc + c[i].sc, c[j].fs.sc, c[j].fs.sc + c[j].sc+1) ){
	  f = true;
	  break;
	}
      }

      if(f){
	c.erase(c.begin()+i);
	i--;
      }
    }

    rep(i,c.size()){
      for(int y=c[i].fs.fs;y<c[i].fs.fs+c[i].sc;y++){
	for(int x=c[i].fs.sc;x<c[i].fs.sc+c[i].sc;x++){
	  carpet[y][x].push_back(c[i]);
	}
      }
    }

    int ans = 0;
    while(true){
      bool f = false;
      rep(i,h)rep(j,w){
	if(rem[i][j] && carpet[i][j].size()==1){
	  f = true;
	  ans++;
	  tri t = carpet[i][j][0];
	  for(int y=t.fs.fs;y<t.fs.fs+t.sc;y++){
	    for(int x=t.fs.sc;x<t.fs.sc+t.sc;x++){
	      rem[y][x] = 0;
	    }
	  }
	}
      }
      if(!f)break;
    }

    depth = h*w;
    search(0);
    
    cout << ans + depth  << endl;
  }
}