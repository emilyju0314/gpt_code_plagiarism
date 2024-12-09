#include<bits/stdc++.h>
using namespace std;
#define INF (1e9)
int main(){
  while(1){
    int N;
    int x[100],y[100];
    vector<int> X,Y;
    int ax=INF,bx=-INF;
    int ay=INF,by=-INF;
    
    scanf("%d",&N);
    if(N==0)break;
    for(int i=0;i<N;i++){
      scanf("%d %d",&x[i],&y[i]);
      X.push_back(x[i]);
      Y.push_back(y[i]);
    }
    for(int i=0;i<4;i++){
      int px,py;
      cin>>px>>py;
      ax=min(ax,px);
      ay=min(ay,py);
      bx=max(bx,px);
      by=max(by,py);
    }
    X.push_back(ax);
    Y.push_back(ay);
    X.push_back(bx);
    Y.push_back(by);
    
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase( unique( X.begin(), X.end() ), X.end() );
    Y.erase( unique( Y.begin(), Y.end() ), Y.end() );
    
    for(int i=0;i<N;i++){
      x[i]=lower_bound(X.begin(),X.end(),x[i])-X.begin();
      y[i]=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin();
    }
    ax=lower_bound(X.begin(),X.end(),ax)-X.begin();
    ay=lower_bound(Y.begin(),Y.end(),ay)-Y.begin();
    bx=lower_bound(X.begin(),X.end(),bx)-X.begin();
    by=lower_bound(Y.begin(),Y.end(),by)-Y.begin();
    vector<int> G[300];
    for(int i=0;i<N;i++){
      int px=x[i],py=y[i];
      int qx=x[ (i+1)%N ];
      int qy=y[ (i+1)%N ];
      if(qy!=py)continue;
      G[py].push_back( min(px,qx) );
      G[py].push_back( max(px,qx) );
    }

    int t[300]={};
    
    long long ans=0;
    for(int py=0;py+1<(int)Y.size();py++){
      for(int i=0;i<(int)G[py].size();i+=2){
        int ax=G[py][i];
        int bx=G[py][i+1];
        for(int px=ax;px<bx;px++){
          t[px]=1-t[px];
        }
      }
      for(int px=0;px+1<(int)X.size();px++){
        if(t[px]==0)continue;
        if(ax<=px&&px<bx&&ay<=py&&py<by)continue;
        long long dy=Y[py+1]-Y[py];
        long long dx=X[px+1]-X[px];
        ans+=dy*dx;
      }
    }
    printf("%lld\n",ans);
  }
  
  return 0;
}