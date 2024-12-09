#include<bits/stdc++.h>
using namespace std;
int H,W,N;
int a[201][201];
int A[201][201];

inline int calc(int h,int w,int H,int W){
  return A[H][W]-A[H][w]-A[h][W]+A[h][w];
}

bool solve(int h,int w,int H,int W,int N,int M){
  int res=0,total=calc(h,w,H,W);
  if(N==1)return (total>=M);
  for(int i=h+1;i<H;i++){
    if(calc(h,w,i,W)<M)continue;
    if(solve(i,w,H,W,N-1,M))return true;
    break;
  }
  for(int j=w+1;j<W;j++){
    if(calc(h,w,H,j)<M)continue;
    if(solve(h,j,H,W,N-1,M))return true;
    break;
  }
  for(int i=H-1;i>h;i--){
    if(calc(i,w,H,W)<M)continue;
    if(solve(h,w,i,W,N-1,M))return true;
    break;
  }
  for(int j=W-1;j>w;j--){
    if(calc(h,j,H,W)<M)continue;
    if(solve(h,w,H,j,N-1,M))return true;
    break;
  }
  return res;
}

bool check(int nv,int sv,int M){
  int ev=0,wv=0;
  while(calc(0,0,wv,nv)<M){
    wv++;
    if(wv>=H)return false;
  }
  while(calc(0,nv,ev,W)<M){
    ev++;
    if(ev>=H)return false;
  }
  if(sv<nv)ev=max(ev,wv);
  if(sv>nv)wv=max(ev,wv);
  if(calc(wv,0,H,sv)<M)return false;
  if(calc(ev,sv,H,W)<M)return false;
  return true;
}

bool check(int M){
  if(N==4)
    for(int nv=1;nv<W;nv++)
      for(int sv=1;sv<W;sv++)
        if(check(nv,sv,M))return true;
  return solve(0,0,H,W,N,M);
}

int compute(){
  int L=0,R=200000001,M;
  while(R-L>1){
    M=(L+R)/2;
    if(check(M))L=M;
    else R=M;
  }
  return L;
}

int main(){
  scanf("%d %d %d",&H,&W,&N);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf("%d",&a[i][j]);
      A[i+1][j+1]=a[i][j]+A[i+1][j]+A[i][j+1]-A[i][j];
    }
  }
  int ans=compute();
  printf("%d\n",ans);
  return 0;
}