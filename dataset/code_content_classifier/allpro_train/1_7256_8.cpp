// #pragma GCC target("avx2")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
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
using namespace std;
const long long mod=1000010007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
long long Comb(int a,int b){
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
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
// ここから編集しろ
long long p[1100][1100];
long long t[1100];
int main(){

	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)scanf("%lld",&p[i][j]);
	}
	for(int i=0;i<a-1;i++)if(p[i][0]>p[i+1][0]){
		printf("-1\n");
		return 0;
	}
	if(b==1){
		for(int i=0;i<a-1;i++)if(p[i][0]>=p[i+1][0]){
			printf("-1\n");
			return 0;
		}
		printf("0\n");	return 0;
	}
	long long ret=0;
	long long cur=0;
	for(int i=1;i<a;i++){
		if(p[i-1][0]!=p[i][0]){cur=0;continue;}
		long long now=p[i-1][0]*cur+p[i-1][1];
		if(p[i][1]>now){
			cur=0;continue;
		}
		long long req=(now-p[i][1]+p[i][0]-1)/p[i][0];

		if(p[i][1]+p[i][0]*req>now){
			cur=req;
			ret+=req;
			continue;
		}
		bool ok=false;
		long long P=ABS(cur-req);
		if(P>mod)return 1;
		if(P==0){

			for(int j=0;j<b;j++){
				if(p[i-1][j]<p[i][j]){ok=true;break;}
				if(p[i-1][j]>p[i][j]){break;}
			}

		}else{
			t[0]=1;
			for(int j=1;j<b;j++){
				if(t[j-1]==mod){t[j]=mod;continue;}
				t[j]=t[j-1]*(P-1+j)/j;
				if(t[j]>mod){
					t[j]=mod;
				}
			}
			for(int j=2;j<b;j++){
				if(req<cur){	
					long long tmp=p[i][j];
					for(int k=j;k>=0;k--){
						tmp-=t[k]*p[i-1][j-k];
						if(tmp<0)break;
					}
					if(tmp<0){
						break;
					}
					if(tmp>0){
						ok=true;break;
					}
				}else{
					long long tmp=p[i-1][j];
					for(int k=j;k>=0;k--){
						tmp-=t[k]*p[i][j-k];
						if(tmp<0)break;
					}
					if(tmp<0){
						ok=true;break;
					}
					if(tmp>0){
						break;
					}
				}
			}			
		}

		if(!ok){
			req++;
		}
		ret+=req;
		cur=req;
	//	printf("%lld %lld\n",ret,cur);
	}
	printf("%lld\n",ret);
}