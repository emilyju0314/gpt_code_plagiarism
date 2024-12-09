#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int mod;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void Ex_gcd(int a,int b,int &x,int &y){
  if (!b) {x=1;y=0;return;}
  Ex_gcd(b,a%b,y,x);
  y-=a/b*x;
}

int Get_inv(int a,int p=mod){int x,y;Ex_gcd(a,p,x,y);return (x%p+p)%p;}

int a,x,b,y;

void into(){
  scanf("%d%d%d%d%d",&a,&x,&b,&y,&mod);
}

void Get_abc(){
  int g=gcd(a,b);
  a/=g;b/=g;mod/=gcd(g,mod);
  g=gcd(a,mod);
  a/=g;y/=g;mod/=g;
  g=gcd(b,mod);
  x/=g;b/=g;mod/=g;
  a%=mod;b%=mod;
}

int d;
vector<int>p,cnt;

void Get_p(){
  if (mod==1) return;
  p.clear();
  cnt.clear();
  d=mul(a,Get_inv(b));
  int invd=Get_inv(d),now=0;
  for (int n=mod,m=d;n;){
	m=(m-1)%n+1;
	int t=n/m;
	p.push_back(mul(now,invd));
	cnt.push_back(t);
	now+=t*m;n-=t*m;
  }
  p.push_back(mod);
}

LL ans;

int Get_y(int x){return x?sub(0,mul(d,x)):mod;}

void Get_ans(){
  if (mod==1) {ans=x+y;return;}
  ans=0;
  for (int vs=cnt.size(),i=0;i<vs;++i){
	int lx=p[i],ly=Get_y(lx),rx=p[i+1],ry=Get_y(rx);
	int dx=(rx-lx)/cnt[i],dy=(ly-ry)/cnt[i];
	//printf("%d %d %d %d %d %d\n",lx,ly,rx,ry,dx,dy);
	LL l=0,r=x+y,s=0;
	for (;l<=r;){
	  LL mid=l+r>>1,p=x-lx*mid,q=y-ry*mid;
	  p>=0&&q>=0&&p/dx+q/dy>=mid*cnt[i]?(s=mid,l=mid+1):r=mid-1;
	}
	ans=max(ans,s);
  }
}

void work(){
  Get_abc();
  Get_p();
  Get_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  int T;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}