#include<queue>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i,j;
  int a[8],c[30][256],m,n,o,u,v,x,y;
  unsigned b[30][30];
  double z;
  priority_queue<pair<double,pair<int,int> >,vector<pair<double,pair<int,int> > >,greater<pair<double,pair<int,int> > > > e;
  while(cin>>m>>n>>o>>u>>v&&m+n+o+u+v){
    u--;
    v--;
    for(i=0;i<m;i++)
      cin>>a[i];
    memset(b,-1,sizeof(b));
    for(i=0;i<o;i++){
      int p,q,r;
      cin>>p>>q>>r;
      p--;
      q--;
      b[p][q]=b[q][p]=r;
    }
    memset(c,-1,sizeof(c));
    while(e.empty()==0)
      e.pop();
    e.push(make_pair(0,make_pair(u,0)));
    while(e.empty()==0){
      z=e.top().first;
      x=e.top().second.first;
      y=e.top().second.second;
      if(x==v)
	break;
      e.pop();
      if(c[x][y]==-1){
	c[x][y]=1;
	for(i=0;i<m;i++){
	  if((y&(1<<i))==0){
	    for(j=0;j<n;j++){
	      if((int)b[x][j]!=-1)
		e.push(make_pair(z+(double)b[x][j]/a[i],make_pair(j,y|(1<<i))));
	    }
	  }
	}
      }
    }
    if(e.empty())
      cout<<"Impossible"<<endl;
    else
      cout<<z<<endl;
  }
  return 0;
}