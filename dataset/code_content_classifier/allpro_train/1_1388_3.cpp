#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int, P > PP;
typedef pair<int, char > PC;

#define MAX 5000000
int cc=1;
int A,B,C,N;
// set< PP > s;
map< PP , int> u;
vector< PP > t;

map< P , set< PC > > xy,yz,zx;

int par[MAX],rak[MAX];

void init(){
  for(int i=0;i<MAX;i++)
    par[i]=i,rak[i]=1;
}

int find(int x){
  if(par[x]==x)return x;
  return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return;
  if(rak[x]<rak[y])swap(x,y);
  par[y]=x;
  rak[x]+=rak[y];
}

void calc(map< P , set<PC> > &mp, int f=0){
  //  map< P , set<PC> > :: iterator it;
  
  for( pair< P, set<PC> > spc : mp){

    set<PC> :: iterator si=spc.second.begin();
    set<PC> :: iterator ti=spc.second.end();
    set<PC> :: iterator A=si,B;
    while(1){
      B=A;
      ++B;
      if(B==ti)break;
      if(A->second>0&&B->second>0){

        PP as,bs;
        if(f==0){
          as.first=spc.first.first;
          as.second.first=spc.first.second;
          as.second.second=A->first;

          bs.first=as.first;
          bs.second.first=as.second.first;
          bs.second.second=B->first;

        }else if(f==1){
          as.first=A->first;
          as.second.first=spc.first.first;
          as.second.second=spc.first.second;

          bs.first=B->first;
          bs.second.first=as.second.first;
          bs.second.second=as.second.second;
        }else{
          as.first=spc.first.second;
          as.second.first=A->first;
          as.second.second=spc.first.first;
          
          bs.first=spc.first.second;
          bs.second.first=B->first;
          bs.second.second=spc.first.first;
        }


        unite( u[as], u[bs] );

      }
      A=B;
    }
  }
}

void add(int nx,int ny,int nz){
  if(nx<0||A<=nx||ny<0||B<=ny||nz<0||C<=nz)return;

  PP pp=PP(nx,P(ny,nz));
  if(u.count(pp))return;
  u[ pp ] = cc;
  xy[ P(nx,ny) ].insert( P(nz,1) );
  yz[ P(ny,nz) ].insert( P(nx,1) );
  zx[ P(nz,nx) ].insert( P(ny,1) );
  
  cc++;
}

int main(){
  init();
  scanf("%d %d %d %d",&A,&B,&C,&N);
  t.resize(N);
  for(int i=0;i<N;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    PP pp=PP(x,P(y,z));
    u[ pp ] = -1;

    t[i]=pp;
    xy[ P(x,y) ].insert( PC(z,0) );
    yz[ P(y,z) ].insert( PC(x,0) );
    zx[ P(z,x) ].insert( PC(y,0) );     
  }

  add(0,0,0);

  for(int i=0;i<(int)t.size();i++){
    int x=t[i].first;
    int y=t[i].second.first;
    int z=t[i].second.second;
    
    for(int dx=-1;dx<=1;dx++){
      for(int dy=-1;dy<=1;dy++){
        for(int dz=-1;dz<=1;dz++){
          add(x+dx,y+dy,z+dz);

          add(x+dx,0,0);
          add(0,y+dy,0);
          add(0,0,z+dz);

          //          add(x+dx,B-1,C-1);
          //          add(A-1,y+dy,C-1);
          //          add(A-1,B-1,z+dz);

          //          add(x+dx,B-1,0);
          //          add(A-1,y+dy,0);
          //          add(A-1,0,z+dz);

          //          add(x+dx,0,C-1);
          //          add(0,y+dy,C-1);
          //          add(0,B-1,z+dz);

                    add(x+dx,y+dy,0);
                    add(0,y+dy,z+dz);
                    add(x+dx,0,z+dz);

          //          add(x+dx,y+dy,C-1);
          //          add(A-1,y+dy,z+dz);
          //          add(x+dx,B-1,z+dz);
        }
      }
    }
  }
  

  calc(xy,0);
  calc(yz,1);
  calc(zx,2);

  int ans=0;
  for(int i=1;i<cc;i++)
    if(find(i)==i)ans++;

  printf("%d\n",ans);
  return 0;
}