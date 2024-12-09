//27
#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<char,char> pcc;

struct S{
  vector<pcc> c;
  pcc p[3];
  char x,y,t;
  int tc()const{
    return x*100+y;
  }
  S(){
    p[0]=p[1]=p[2]=pcc(-1,-1);
  }
  bool operator<(S a)const{
    if(tc()!=a.tc()){
      return tc()<a.tc();
    }else if(c!=a.c){
      return c<a.c;
    }else{
      return lexicographical_compare(p,p+3,a.p,a.p+3);
    }
  }
  bool isc(int x,int y){
    return find(c.begin(),c.end(),pcc(x,y))!=c.end();
  }
  bool isp(int x,int y){
    return find(p,p+3,pcc(x,y))!=p+3;
  }
  bool isf(int x,int y){
    return !isc(x,y)&&!isp(x,y);
  }
};

struct cmp{
  bool operator ()(S a,S b)const{
    return a.t>b.t;
  }
};

int main(){
  for(int h,w;cin>>h>>w,h|w;){
    char g[10][10];
    S is;
    is.t=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>>g[i][j];
	if(g[i][j]=='@'){
	  is.x=j;
	  is.y=i;
	}else if(g[i][j]=='w'){
	  *find(is.p,is.p+3,pcc(-1,-1))=pcc(j,i);
	}else if(g[i][j]=='c'){
	  is.c.push_back(pcc(j,i));
	}
      }
    }
    priority_queue<S,vector<S>,cmp> que;
    que.push(is);
    set<S> p;
    while(!que.empty()){
      S c=que.top();
      if(g[c.y][c.x]=='E')break;
      que.pop();
      if(!p.insert(c).second)continue;
      for(int i=0;i<4;i++){
	int d[]={0,1,0,-1,0};
	int xd=d[i];
	int yd=d[i+1];
	int ny=c.y+yd;
	int nx=c.x+xd;
	if(c.isc(nx,ny)){
	  S n=c;
	  n.c.erase(find(n.c.begin(),n.c.end(),pcc(nx,ny)));
	  do{
	    ny+=yd;
	    nx+=xd;
	  }while(n.isf(nx,ny)&&g[ny][nx]!='#');
	  if(n.isp(nx,ny)){
	    pcc *x=find(n.p,n.p+3,pcc(nx,ny));
	    *x=pcc(-1,-1);
	  }else{
	    n.c.push_back(pcc(nx-xd,ny-yd));
	  }
	  que.push(n);
	}else if(c.isf(nx,ny)&&g[ny][nx]!='#'){
	  S n=c;
	  n.x=nx;
	  n.y=ny;
	  n.t++;
	  que.push(n);
	}
      }
    }
    cout<<(que.empty()?-1:que.top().t)<<endl;
  }
  return 0;
}
	