#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int f(int a[][16],int b[][16],int c[16][16],int x,int y,int gx,int gy){
  int s=0;
  if(x==gx&&y==gy)
    return 1;
  if(c[x][y]!=-1)
    return c[x][y];
  if(a[x][y]==0)
    s+=f(a,b,c,x,y+1,gx,gy);
  if(b[x][y]==0)
    s+=f(a,b,c,x+1,y,gx,gy);
  c[x][y]=s;
  return s;
}
int main(){
  int h,i,j;
  int a[16][16],b[16][16],c[16][16],gx,gy,m,n,s;
  memset(a,-1,sizeof(a));
  memset(b,-1,sizeof(b));
  cin>>m;
  for(h=0;h<m;h++){
    cin>>gx>>gy>>n;
    for(i=0;i<gy;i++)
      for(j=0;j<gx+1;j++)
	a[j][i]=0;
    for(i=0;i<gy+1;i++)
      for(j=0;j<gx;j++)
	b[j][i]=0;
    for(i=0;i<n;i++){
      int t,u,v,w;
      cin>>t>>u>>v>>w;
      if(t==v)
	a[t][min(u,w)]=-1;
      else
	b[min(t,v)][u]=-1;
    }
    memset(c,-1,sizeof(c));
    s=f(a,b,c,0,0,gx,gy);
    if(s)
      cout<<s<<endl;
    else
      cout<<"Miserable Hokusai!"<<endl;
  }
  return 0;
}