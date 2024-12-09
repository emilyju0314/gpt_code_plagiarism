#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef double Real;
typedef complex<Real> P;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

#define MOD 1000000007
#define eps 1e-8

int n,m;
P cvx[125];
P pts[125];

Real cross(P a, P b){
  return imag(conj(a)*b);
}
Real dot(P a, P b){
  return real(conj(a)*b);
}

bool inner(P p){
  P g = (cvx[0] + cvx[n/3] + cvx[2*n/3]) / 3.0;
  // g += P(1e-7, 1e-7);
  int a = 0, b = n;
  while(a+1<b){
    int c = (a+b)/2;
    if(cross(cvx[a]-g, cvx[c]-g)>0){
      if(cross(cvx[a]-g, p-g)>0 && cross(cvx[c]-g, p-g)<0) b=c;
      else a=c;
    }else{
      if(cross(cvx[a]-g, p-g)<0 && cross(cvx[c]-g, p-g)>0) a=c;
      else b=c;
    }
  }
  b %= n;
  if(cross(cvx[a]-p, cvx[b]-p)<-eps) return false;
  return true;
}

bool inner2(P p){
  bool in = false;
  REP(i,n){
    P a = cvx[i]-p;
    P b = cvx[(i+1)%n]-p;
    if(imag(a)>imag(b))swap(a,b);
    if(imag(a)<=0 && 0<imag(b)){
      if(cross(a,b)<0)in = !in;
    }
    if(abs(cross(a,b))<eps && dot(a,b)<=0)return true;
  }
  return in;
}

int main(){
  scanf("%d",&n);
  REP(i,n){
    Real x,y;
    scanf("%lf%lf",&x,&y);
    cvx[i] = P(x,y);
  }
  scanf("%d",&m);
  REP(i,m){
    Real x,y;
    scanf("%lf%lf",&x,&y);
    pts[i] = P(x,y);
  }
  vector<P> po;
  const Real PI = 4.0*atan(1.0);

  REP(i,n)po.push_back(cvx[i]);

  REP(i,m)REP(j,i){
    P a = pts[i], b = pts[j];
    P s1 = (a+b)/2.0;
    P d1 = (b-a)*exp(P(0,PI/2.0));
    REP(ii,n){
      P x = cvx[ii], y = cvx[(ii+1)%n];
      P s2 = x;
      P d2 = y-x;
      if(cross(d1,s2-s1)*cross(d1,s2+d2-s1) >= eps)continue;
      if(abs(cross(d2,d1))<eps)continue;
      P o = s1 + d1*cross(d2, s2-s1)/cross(d2, d1);
      // #define X real()
      // #define Y imag()
      // if(x.X <= y.X && (o.X < x.X-eps || o.X > y.X+eps))continue;
      // if(x.X >= y.X && (o.X > x.X+eps || o.X < y.X-eps))continue;
      // if(x.Y <= y.X && (o.Y < x.Y-eps || o.Y > y.Y+eps))continue;
      // if(x.Y >= y.X && (o.Y > x.Y+eps || o.Y < y.Y-eps))continue;
      po.push_back(o);
    }
  }

  REP(i,m)REP(j,i)REP(k,j){
    P a = pts[i], b = pts[j], c = pts[k];
    if(abs(cross(b-a,c-a))<eps)continue;
    P ab = (a+b)/2.0;
    P ac = (a+c)/2.0;
    P abd = (b-a)*exp(P(0,PI/2.0));
    P acd = (c-a)*exp(P(0,PI/2.0));
    P o = ab + abd * cross(acd, ac-ab) / cross(acd, abd);
    if(inner2(o))po.push_back(o);
  }

  Real ans = 0.0;
  REP(i,po.size()){
    P o = po[i];
    Real tmp = 1e18;
    REP(ii,m){
      CHMIN(tmp, abs(pts[ii]-o));
    }
    CHMAX(ans, tmp);
  }
  printf("%.9f\n",ans);
  return 0;
}

