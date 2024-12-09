#include<bits/stdc++.h>
#define eps 0.000000001
using namespace std;
typedef long double ld;
typedef pair<int,int> p;
typedef pair<ld,p> P;

int n;
ld px[200],py[200],pz[200],vx[200],vy[200],vz[200],r[200],vr[200];

ld getlen(int a,int b,ld M){
  ld ax=px[a]+vx[a]*M,ay=py[a]+vy[a]*M,az=pz[a]+vz[a]*M,ar=r[a]-vr[a]*M;
  ld bx=px[b]+vx[b]*M,by=py[b]+vy[b]*M,bz=pz[b]+vz[b]*M,br=r[b]-vr[b]*M;
  ld dx=ax-bx,dy=ay-by,dz=az-bz;
  return sqrt(dx*dx+dy*dy+dz*dz)-(ar+br);
}

ld check(int a,int b){
  ld mt=min(r[a]/vr[a],r[b]/vr[b]);
  ld L=0,R=mt,M;
  int s=0;
  while(s++<50){
    M=(L+R)/2;
    ld len=getlen(a,b,M),len1=getlen(a,b,M+eps);
    if(len<len1||len<=0)R=M;
    else L=M;
  }
  if(R==mt||L==0||getlen(a,b,R)>0)return 1000;
  return R;
}

int main(){
  while(cin>>n,n){
    for(int i=0;i<n;i++)
      cin>>px[i]>>py[i]>>pz[i]>>vx[i]>>vy[i]>>vz[i]>>r[i]>>vr[i];
    priority_queue<P,vector<P>,greater<P> > q;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++)
	q.push(P(check(i,j),p(i,j)));
      q.push(P(r[i]/vr[i],p(i,i)));
    }
    ld used[200]={};
    while(!q.empty()){
      ld t=q.top().first;
      int a=q.top().second.first,b=q.top().second.second;
      q.pop();
      if(used[a]||used[b])continue;
      used[a]=used[b]=t;
    }
    for(int i=0;i<n;i++)printf("%.10Lf\n",used[i]);
  }
  return 0;
}