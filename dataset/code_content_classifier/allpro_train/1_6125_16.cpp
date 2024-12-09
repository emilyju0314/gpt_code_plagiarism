#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
 
template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;
 
	constexpr static uint mod = mod_;
 
	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<1000000007>;
 
mint C[1001][1001];
mint ex(mint x,int p){
	mint a = 1;
	while(p){
		if(p%2) a*=x;
		x*=x;
		p/=2;
	}
	return a;
}
 
mint dp1[401][401];
mint f1[401][401];
mint f2a[401];
mint f2b[401];
 
void calcdp1(int H,int W,int D){
	dp1[0][0]=1;
	rep(i,H) rep(j,W+1){
		rep(k,W-j+1){
			dp1[i+1][j+k] += dp1[i][j]*C[W-j][k]*ex(D-1,k)*(ex(D,j)-(k==0?1:0));
			//all 0 is out
		}
	}
	rep(h,H+1) rep(w,W+1){
		dp1[h][w] = dp1[h][w]/C[W][w];
	}
//	rep(h,H+1) rep(w,W+1) printf("dp1[%d][%d]=%lld\n",h,w,dp1[h][w]);
//	puts("");
}
mint calc1(int a,int b,int c,int W,int H,int D){
	int X=a/W,Y=b/H,Z=c/D;
	calcdp1(X,Y,D);
	mint ret = 0;
	rep1(x,X) rep1(y,Y){
		if(x==X&&y==Y) f1[x][y]=D;
		else f1[x][y] = dp1[X-x][Y-y]*D*W*H*C[X][x]*C[Y][y];
//		printf("f1[%d][%d]=%lld\n",x,y,f1[x][y]);
		if(x==X&&y==Y) break;	//all same
		ret += f1[x][y]*ex( ex(H,x)+ex(W,y)-1 ,Z);
	}
//	printf("calc1=%lld\n",ret);
	return ret;
}
mint calc2(int a,int b,int c,int W,int H,int D,bool t){
	int X=a/W,Y=b/H,Z=c/D;
	mint ret=0;
	mint* f2=(t?f2a:f2b);
	rep1(x,X){
		f2[x] = mint(1)*W*C[X][x]*ex(D,x)*ex(ex(D,Y)-D,X-x)*ex(H,X-x);
//		printf("f2[%d]=%lld\n",x,f2[x]);
		rep1(y,Y){
			if(y!=Y) f2[x] -= (t?f1[y][x]:f1[x][y]);
			else f2[x] -= mint(1)*W*(t?f1[y][x]:f1[x][y]);
//			printf("f2-=%lld\n",(t?f1[y][x]:f1[x][y]));
		}
		ret += f2[x]*ex(H,x*Z);
	}
//	printf("calc2=%lld\n",ret);
	return ret;
}
mint calc3(int a,int b,int c,int W,int H,int D){
	int X=a/W,Y=b/H,Z=c/D;
	mint ret=0;
	ret += mint(1)*W*(ex(H,X)-H)*ex(ex(D,Y)-D,X);
	ret += mint(1)*H*(ex(W,Y)-W)*ex(ex(D,X)-D,Y);
 
	mint field=ex(D,X*Y)*W*H;
	rep1(x,X) field -= C[X][x]*ex(D,x)*ex(ex(D,Y)-D,X-x)*W*H;
	rep1(y,Y) field -= C[Y][y]*ex(D,y)*ex(ex(D,X)-D,Y-y)*W*H;
	rep1(x,X) rep1(y,Y){
		if(x==X&&y==Y) field += f1[x][y]*H*W;
		else field += f1[x][y];
	}
//	show(field);
	ret += field;
//	printf("calc3=%lld\n",ret);
	return ret;
}
mint calc4(int a,int b,int c,int W,int H,int D){
	int X=a/W,Y=b/H,Z=c/D;
	mint ret = mint(1)*D*ex( ex(H,X)*W+ex(W,Y)*H-H*W , Z );
//	printf("calc4=%lld\n",ret);
	return ret;
}
mint solve(int a,int b,int c,int W,int H,int D){
	if(a%W>0||b%H>0||c%D>0) return 0;
	mint ans=0;
	ans += calc1(a,b,c,W,H,D);
	ans += calc2(a,b,c,W,H,D,0);
	ans += calc2(b,a,c,H,W,D,1);
	ans += calc3(a,b,c,W,H,D);
	ans += calc4(a,b,c,W,H,D);
	return ans;
}
int main(){
	for(int i=0;i<=1000;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
	}
	int a,b,c,W,H,D;
	cin>>W>>H>>D>>a>>b>>c;
	cout<<solve(a,b,c,W,H,D)<<endl;
}