#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define cl(x) memset(x,0,sizeof(x))
#define read(x) scanf("%d",&(x));
using namespace std;

inline double sqr(int x){ return x*x; }

const int N=305;

struct PP{
  int x,y;
  friend double dist(PP A,PP B){
    return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
  }
}s[N],t[N];

int n; double w[N][N];
int boy[N]; double sla[N],lx[N],ly[N];
int S[N],T[N];

inline bool match(int u){
  S[u]=1;
  for (int v=1;v<=n;v++){
    if (T[v]) continue;
    if (fabs(lx[u]+ly[v]-w[u][v])<1e-10){
      T[v]=1;
      if (!boy[v] || match(boy[v]))
	return boy[v]=u,1;
    }else
      sla[v]=min(sla[v],lx[u]+ly[v]-w[u][v]);
  }return 0;
}

inline double KM(){
  for (int i=1;i<=n;i++){
    lx[i]=-1<<30;
    for (int j=1;j<=n;j++)
      lx[i]=max(lx[i],w[i][j]);
  }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++) sla[j]=1<<30;
    while (1){
      cl(S); cl(T); if (match(i)) break;
      double a=1<<30;
      for (int j=1;j<=n;j++) if (!T[j]) a=min(a,sla[j]);
      for (int j=1;j<=n;j++) if (S[j]) lx[j]-=a;
      for (int j=1;j<=n;j++) if (T[j]) ly[j]+=a; else sla[j]-=a;
    }
  }
  double ret=0;  
  for (int i=1;i<=n;i++) if (boy[i]) ret-=w[boy[i]][i];  
  return ret;
}

double ans=0;

int main(){
  read(n); read(s[1].x); read(s[1].y);
  for (int i=1;i<=n;i++){
    read(s[i].x); read(s[i].y);
    read(t[i].x); read(t[i].y);
    ans+=dist(s[i],t[i]);
  }
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
      w[i][j]=-dist(t[i],s[j]);
  ans+=KM();
  printf("%.10lf\n",ans);
  return 0;
}