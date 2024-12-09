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
template<class T>
ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"sz="<<vc.size()<<endl<<"[";
	for(T& v:vc) o<<v<<",";
	o<<"]"<<endl;
	return o;
}
// Z/pZ
typedef int ll;
struct mint{
	const static ll mod=2;
	ll a;
	mint():a(0){}
	mint(ll a):a((a%mod+mod)%mod){}
	mint operator+=(const mint& b){ if((a+=b.a)>=mod) a-=mod; return *this;}
	mint operator-=(const mint& b){ if((a+=mod-b.a)>=mod) a-=mod; return *this;}
	mint operator*=(const mint& b){ (a*=b.a)%=mod; return *this;}
	mint operator+(const mint& b){ return mint(*this)+=b;}
	mint operator-(const mint& b){ return mint(*this)-=b;}
	mint operator*(const mint& b){ return mint(*this)*=b;}
	mint operator-(){ return mint(-a); }
	int extgcd(int a,int b,int &x,int &y) const{
		int u[]={a,1,0},v[]={b,0,1};
		while(*v){
			int t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	mint inv() const{
		int x,y;
		extgcd(a,mod,x,y);
		if(x<0) x+=mod;
		return mint(x);
	}
	mint operator/=(const mint& b){ (*this)*=b.inv(); return *this; }
	mint operator/(const mint& b){ return mint(*this)/=b;}
	bool operator==(const mint& b) const { return a==b.a;}
	friend ostream& operator<<(ostream &o,const mint& x){ return o<<x.a;}
};
const mint zero(0),one(1);
bool iszero(mint x){
	return x.a==0;
}
template<class T>
struct Matrix{
	int H,W;
	vector< vector<T> > m;
	Matrix():H(0),W(0){}
	Matrix(int H,int W):H(H),W(W),m( vector< vector<T> >(H,vector<T>(W,zero)) ){}
	//???0*W?????????????????¨?£????????????§??±????????????????????????????????§???????????????
	//Matrix(vector< vector<T> > m):m(m),H(m.size()),W(m[0].size()){}
	vector<T> const& operator[](const int& i) const {return m[i];}
	vector<T>& operator[](const int& i) {return m[i];}
	Matrix operator+=(const Matrix& b){
		assert(H==b.H&&W==b.W);
		rep(i,H) rep(j,H) m[i][j]+=b[i][j];
		return *this;
	}
	Matrix operator-=(const Matrix& b){
		assert(H==b.H&&W==b.W);
		rep(i,H) rep(j,H) m[i][j]-=b[i][j];
		return *this;
	}
	Matrix operator+(const Matrix& b){return Matrix(*this)+=b;}
	Matrix operator-(const Matrix& b){return Matrix(*this)-=b;}
	Matrix operator*(const Matrix& b){
		assert(W==b.H);
		Matrix c(H,b.W);
		rep(i,H) rep(k,W) rep(j,b.W)c[i][j]+=m[i][k]*b[k][j];
		return c;
	}
	Matrix operator*=(const Matrix& b){return (*this)=(*this)*b;}
	vector<T> operator*(const vector<T>& b){
		assert(W==b.size());
		vector<T> c(H);
		rep(i,H) rep(j,W) c[i]+=m[i][j]*b[j];
		return c;
	}
	static Matrix E(int N){
		Matrix a(N,N);
		rep(i,N) a[i][i]=one;
		return a;
	}
	Matrix ex(int t) {
//		assert(H==W);
		Matrix x=Matrix::E(H),b=(*this);
		while(t){
			if(t%2) x*=b;
			b*=b;
			t/=2;
		}
		return x;
	}
	int sweep(int var=-1){			//return rank ????????¨		swap!!!
		if(var<0) var=W;
		int r=0;
		rep(i,var){
			if(iszero(m[i][i])){
				for(int j=i+1;j<H;j++) if(!iszero(m[j][i])){
					for(int k=i;k<W;k++) swap(m[i][k],m[j][k]);
					break;
				}
				if(iszero(m[i][i])) continue;
			}
			T t=m[i][i];
			rep(k,W) m[i][k]/=t;
			rep(k,H) if(k!=i){
				t=m[k][i];
				rep(l,W) m[k][l]=m[k][l]-m[i][l]*t;
			}
//			show((*this));
		}
		return r;
	}
	T det(){			//????????¨??????!
		T d=one;
		assert(H==W);
		rep(i,H){
			if(iszero(m[i][i])){
				for(int j=i+1;j<H;j++) if(!iszero(m[j][i])){
					for(int k=i;k<W;k++) swap(m[i][k],m[j][k]);
					d=-d;
					break;
				}
				if(iszero(m[i][i])) return zero;
			}
			T t=m[i][i];
			d*=t;
			rep(k,W) m[i][k]/=t;
			rep(k,H) if(k!=i){
				t=m[k][i];
				rep(l,W) m[k][l]=m[k][l]-m[i][l]*t;
			}
//			show((*this));
		}
		return d;
	}
	Matrix inv(){
		assert(H==W);
		Matrix a(H,2*H);
		rep(i,H) rep(j,H) a[i][j]=m[i][j];
		rep(i,H) a[i][i+H]=one;
		int r=a.sweep(H);
		if(r<H) return Matrix();
		Matrix b(H,H);
		rep(i,H){
			rep(j,H) b[i][j]=a[i][j+H];
		}
		return b;
	}
	pair< int,vector<T> > sle(vector<T> b){		// return pair( ?§£????¬????(?????????????????????-1) ,x s.t.Ax=b)
		assert(H==b.size());
		Matrix a(H,W+1);
		rep(i,H) rep(j,W) a[i][j]=m[i][j];
		rep(i,H) a[i][W]=b[i];
		a.sweep(W);
		int d=0;
		rep(i,H){
			bool all0=1;
			rep(j,W) if(!iszero(a[i][j])) all0=0;
			if(all0){
				if(!iszero(a[i][W])){
					return pair<int,vector<T> >(-1,vector<T>());
				}
				d++;
			}
		}
		rep(i,H) b[i]=a[i][W];
		return pair<int,vector<T> >(d,b);
	}
	friend ostream& operator<<(ostream &o,const Matrix& m){
		o<<m.H<<" * "<<m.W<<endl;
		rep(i,m.H){
			o<<"[";
			rep(j,m.W) o<<m[i][j]<<" ";
			o<<"]"<<endl;
		}
		return o;
	}
};
int main(){
	int N,T;
	cin>>N;
	Matrix<mint> a(N,N);
	rep(i,N) rep(j,N){
		int x;
		cin>>x;
		a[i][j]=mint(x);
	}
	vector<mint> b(N);
	rep(i,N){
		int x;
		cin>>x;
		b[i]=mint(x);
	}
	cin>>T;
	a=a.ex(T);
	auto p=a.sle(b);
	if(p.fs==-1){
		puts("none");
	}else if(p.fs>0){
		puts("ambiguous");
	}else{
		rep(i,N) cout<<p.sc[i]<<(i==N-1?"\n":" ");
	}
}