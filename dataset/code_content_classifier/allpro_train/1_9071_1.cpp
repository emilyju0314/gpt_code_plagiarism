// #pragma GCC target("avx")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
// #define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
// #define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<complex>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double INF=1e+10;
const long double PI=acos(-1.0);
const int C_SIZE = 3100000;
const int UF_SIZE = 3100000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	inline long long Comb(int a,int b){
	 	if(a<b||b<0)return 0;
	 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
	}
	void init_C(int n){
		fact[0]=finv[0]=inv[1]=1;
		for(int i=2;i<n;i++){
			inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
		}
		for(int i=1;i<n;i++){
			fact[i]=fact[i-1]*i%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	long long pw(long long a,long long b){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return ret;
	}
	long long pw_mod(long long a,long long b,long long M){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%M;
			a=a*a%M;
			b/=2;
		}
		return ret;
	}
	int pw_mod_int(int a,int b,int M){
		if(a<0)return 0;
		if(b<0)return 0;
		int ret=1;
		while(b){
			if(b%2)ret=(long long)ret*a%M;
			a=(long long)a*a%M;
			b/=2;
		}
		return ret;
	}
	int ABS(int a){return max(a,-a);}
	long long ABS(long long a){return max(a,-a);}
	double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
	int UF[UF_SIZE];
	void init_UF(int n){
		for(int i=0;i<n;i++)UF[i]=-1;
	}
	int FIND(int a){
		if(UF[a]<0)return a;
		return UF[a]=FIND(UF[a]);
	}
	void UNION(int a,int b){
		a=FIND(a);b=FIND(b);if(a==b)return;
		if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// ここから編集しろ
long long X[11000];
long long Y[11000];
int n;
int calc(long long x,long long y){
	if(x<0)return 0;
	int ret=0;
	for(int i=0;i<n;i++){
		long long N=x+y-X[i]-Y[i];
		long long K=y-Y[i];
		// printf("%lld %lld\n",N,K);
		if(K<0||N<K)continue;
		if((N&K)==K)ret++;
	}
	// printf("%lld %lld: %d\n",x,y,ret);
	return ret%2;
}
int main(){
	int a;scanf("%d",&a);n=a;
	for(int i=0;i<a;i++){
		scanf("%lld%lld",X+i,Y+i);
		X[i]+=100000000000000000LL;
		Y[i]+=100000000000000000LL;
	}
	long long KM=inf;
	for(int i=0;i<a;i++)KM=min(KM,X[i]+Y[i]);
	while(1){
		int I=rand()%a;
		long long LM=X[I]+Y[I];
		// if(rand()%4==0)LM=X[I];
		// if(rand()%4==0)LM=Y[I];
		
		long long D=LM+(1LL<<60)-1;
		if(rand()%3<2)D=LM+(1LL<<60)-1+rand()%300;
		long long tx=D/mod*(rand()%mod);
		long long ty=D-tx;
		if(rand()%3==0){
			tx=X[I];
			ty=D-tx;
		}
		if(calc(tx,ty)==0)continue;
		for(int i=60;i>=0;i--){
			if(ty-(1LL<<i)>=0&&calc(tx+(1LL<<i),ty-(1LL<<i))){
				tx+=(1LL<<i);
				ty-=(1LL<<i);
			}
		}
		long long tmp=0;
		for(int i=0;i<=60;i++){
			if(calc(tx-(1LL<<i),ty+(1LL<<i)))tmp+=(1LL<<i);
		}

		long long rx=tx-tmp;
		long long ry=ty;
		rx-=100000000000000000LL;
		ry-=100000000000000000LL;
		
		printf("%lld %lld\n",rx,ry);
		break;
	}
}