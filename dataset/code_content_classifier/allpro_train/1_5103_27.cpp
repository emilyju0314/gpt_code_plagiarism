#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{
  ll x,y;
};

ll w,h,v,t,x,y,p,q;
ll R,H,W;
point o,O;

point calc(ll X,ll Y){
  ll dx=abs(X-O.x),dy=abs(Y-O.y);
  point res;

  if(dx%2==0)res.x=p;
  else res.x=w-p;

  if(dy%2==0)res.y=q;
  else res.y=h-q;

  res.x+=X*w;
  res.y+=Y*h;
  return res;
}

ll search(ll Y){
  ll l=0,r=W,m;
  while(l<r){
    m=(l+r)/2;
    point d=calc(m,Y);
    ll dist= (d.x-o.x)*(d.x-o.x) + (d.y-o.y)*(d.y-o.y);
    if( dist <= v*t*v*t  || o.x< d.x ){
      r=m;
    }else{
      l=m+1;
    }
  }
  return l;
}

ll search2(ll Y){
  ll l=0,r=W,m;
  while(l<r){
    m=(l+r)/2;
    point d=calc(m,Y);
    ll dist= (d.x-o.x)*(d.x-o.x) + (d.y-o.y)*(d.y-o.y);
    if( dist <= v*t*v*t || d.x < o.x ){
      l=m+1;
    }else{
      r=m;
    }
  }
  return l;
}

int main(){
  cin>>w>>h>>v>>t>>x>>y>>p>>q;
  R=v*t;
  W=(v*t/w+1LL)*4;
  H=(v*t/h+1LL)*4;
  O.x=W/2;
  O.y=H/2;
  o.x=O.x*w+x;
  o.y=O.y*h+y;



  ll ans=0;
  for(ll i=0;i<=H;i++){
    ll a=search(i);
    ll b=search2(i);
    point d=calc(a,i);
    ll dist= (d.x-o.x)*(d.x-o.x) + (d.y-o.y)*(d.y-o.y);
    d=calc(b,i);
    ll dist2= (d.x-o.x)*(d.x-o.x) + (d.y-o.y)*(d.y-o.y);
    d=calc(b-1,i);
    ll dist3= (d.x-o.x)*(d.x-o.x) + (d.y-o.y)*(d.y-o.y);
    d=calc(a-1,i);
    ll dist4= (d.x-o.x)*(d.x-o.x) + (d.y-o.y)*(d.y-o.y);

    if(dist <= v*t*v*t && v*t*v*t<dist2)
      if(dist3 <= v*t*v*t &&v*t*v*t<dist4)
	ans+=(b-a);
    
  }
  cout<<ans<<endl;
  return 0;
}