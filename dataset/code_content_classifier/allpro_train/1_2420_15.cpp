#include<map>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cassert>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

/*** RATIONAL LIBRARY BEGIN ***/
template<class T>
class rational{
	T nu,de;
	void reg(){ if(de<0) nu*=-1, de*=-1; }

public:
	// constructor
	rational():nu(0),de(1){}
	rational(const T &v):nu(v),de(1){}
	rational(const T &n,const T &d):nu(n),de(d){
		T g=gcd(nu,de);
		nu/=g;
		de/=g;
		reg();
	}

	// getter
	const T &n(){ return nu; }
	const T &d(){ return de; }

	// 算術演算
	rational &operator+=(const rational &r){
		T g=gcd(de,r.de);
		de/=g;
		nu=nu*(r.de/g)+r.nu*de;
		g=gcd(nu,g);
		nu/=g;
		de*=r.de/g;
		reg();
		return *this;
	}

	rational &operator-=(const rational &r){
		T g=gcd(de,r.de);
		de/=g;
		nu=nu*(r.de/g)-r.nu*de;
		g=gcd(nu,g);
		nu/=g;
		de*=r.de/g;
		reg();
		return *this;
	}

	rational &operator*=(const rational &r){
		T g1=gcd(nu,r.de),g2=gcd(de,r.nu);
		nu=(nu/g1)*(r.nu/g2);
		de=(de/g2)*(r.de/g1);
		reg();
		return *this;
	}

	rational &operator/=(const rational &r){
		T g1=gcd(nu,r.nu),g2=gcd(de,r.de);
		nu=(nu/g1)*(r.de/g2);
		de=(de/g2)*(r.nu/g1);
		reg();
		return *this;
	}

	rational operator+(const rational &r)const{ return rational(*this)+=r; }
	rational operator-(const rational &r)const{ return rational(*this)-=r; }
	rational operator*(const rational &r)const{ return rational(*this)*=r; }
	rational operator/(const rational &r)const{ return rational(*this)/=r; }

	rational operator-()const{ return rational<T>(-nu,de); }

	// 比較演算
	bool operator<(const rational &r)const{ return nu*r.de<r.nu*de; } // overflow 注意
	bool operator>(const rational &r)const{ return r<*this; }
	bool operator<=(const rational &r)const{ return !(r<*this); }
	bool operator>=(const rational &r)const{ return !(*this<r); }
	bool operator==(const rational &r)const{ return nu==r.nu && de==r.de; }
	bool operator!=(const rational &r)const{ return !(*this==r); }
};
/*** RATIONAL LIBRARY END ***/

rational<ll> abs(const rational<ll> &r){ return r>=0?r:-r; }

void operator+=(vector<ll> &a,const vector<ll> &b){ rep(i,80) a[i]+=b[i]; }

int row;
ll A[80][80]; // 係数行列

map<string,int> f; // 原子の名前 -> id

int idx;
char s[128];

vector<ll> molecule();

int number(){
	int num=0;
	while(isdigit(s[idx])) num=num*10+(s[idx++]-'0');
	return num;
}

vector<ll> chemical_element(){
	string name;
	name+=s[idx++];
	if(islower(s[idx])) name+=s[idx++];

	int id;
	if(f.count(name)!=0) id=f[name];
	else{
		id=f.size();
		f[name]=id;
	}

	vector<ll> a(80);
	a[id]=1;
	return a;
}

vector<ll> unit_group(){
	if(s[idx]!='('){
		return chemical_element();
	}
	else{
		idx++;
		vector<ll> a=molecule();
		assert(s[idx++]==')');
		return a;
	}
}

vector<ll> group(){
	vector<ll> a=unit_group();
	if(isdigit(s[idx])){
		int num=number();
		rep(i,80) a[i]*=num;
	}
	return a;
}

vector<ll> molecule(){
	vector<ll> a=group();
	while(isupper(s[idx]) || s[idx]=='(') a+=group();
	return a;
}

void molecule_sequence(int sign){
	vector<ll> a=molecule();
	rep(i,80) A[row][i]+=sign*a[i];
	for(row++;s[idx]=='+';row++){
		idx++;
		a=molecule();
		rep(i,80) A[row][i]+=sign*a[i];
	}
}

void chemical_equation(){
	molecule_sequence(+1);
	assert(s[idx++]=='-');
	assert(s[idx++]=='>');
	molecule_sequence(-1);
	assert(s[idx++]=='.');
}

void parse(){
	f.clear();
	rep(i,80) rep(j,80) A[i][j]=0;
	idx=row=0;
	chemical_equation();
}

const int N_MAX=80;
void Gauss_Jordan(int n,const rational<ll> A[N_MAX][N_MAX],const rational<ll> *b,rational<ll> *x){
	static rational<ll> B[N_MAX][N_MAX+1];
	rep(i,n){
		rep(j,n) B[i][j]=A[i][j];
		B[i][n]=b[i];
	}

	rep(i,n){
		int piv=i;
		for(int j=i;j<n;j++) if(abs(B[j][i])>abs(B[piv][i])) piv=j;
		rep(j,n+1) swap(B[i][j],B[piv][j]);

		if(B[i][i]==0) break;

		for(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
		rep(j,n) if(i!=j) for(int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];
	}

	rep(i,n) x[i]=B[i][n];
}

int main(){
	for(;fgets(s,128,stdin),s[0]!='.';){
		parse();

		rational<ll> A[80][80],b[80],x[80];
		rep(i,80) rep(j,80) A[j][i]=::A[i][j];
		A[79][0]=b[79]=1; // 一つめの変数の値を 1 に固定する

		Gauss_Jordan(80,A,b,x);

		ll L=1;
		rep(i,row) L=lcm(L,x[i].d());
		rep(i,row) x[i]*=L;
		ll G=0;
		rep(i,row) G=gcd(G,x[i].n());
		rep(i,row) x[i]/=G;
		rep(i,row) printf("%lld%c",x[i].n(),i<row-1?' ':'\n');
	}

	return 0;
}