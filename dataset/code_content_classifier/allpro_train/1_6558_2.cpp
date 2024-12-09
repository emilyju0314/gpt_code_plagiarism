#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
     if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int M=600002,N=M+2,mod=1e9+7;
const ll mod2=(ll)mod*mod*7;
ll fac[N],ni[N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll c(int a,int b){
	return b>=0&&a>=b?fac[a]*ni[b]%mod*ni[a-b]%mod:0;
}
ll C(int a,int b){
	return (b&1)?mod-c(a,b):c(a,b);
}
int solve(int n,int m,int x){
	ll ans=0;
	For(i,1,x/m){
		For(j,0,(x-i*m)/i){
			int sy=x-i*m-j*i;
			ans+=C(n-m,j)*c(sy+n,n);
			if(ans>=mod2)ans-=mod2;
		}
		if(i>1)For(j,0,(x-i*m)/(i-1)){
			int sy=x-i*m-j*(i-1);
			ans-=C(n-m,j)*c(sy+n,n);
			if(ans<0)ans+=mod2;
		}
	}
	ans%=mod; 
	ans=(c(x+n,n)-ans*c(n,m)%mod+mod)%mod;
	return ans;
}
int main(){
	For(i,fac[0]=1,M)fac[i]=fac[i-1]*i%mod;
	ni[M]=ksm(fac[M],mod-2);
	Rep(i,M,1)ni[i-1]=ni[i]*i%mod;
	int n=read(),m=read(),l=read(),r=read();
	writeln((solve(n,m,r)-solve(n,m,l-1)+mod)%mod);
}