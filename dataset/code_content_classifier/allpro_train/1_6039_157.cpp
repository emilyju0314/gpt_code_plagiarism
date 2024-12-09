#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}

const int cys=1000000007;
int n,k,m;
ll d[25005][405],s[25005][405],a[25005],cnt[405],pw[25005],fac[405],inv[405];
bool vis[405];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); k=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i]=readint();
	d[0][k]=s[0][k]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<k;j++) d[i][j]=(d[i-1][j+1]*(k-j)+s[i-1][j])%cys;
		d[i][k]=d[i-1][k]*k%cys;
		for(int j=1;j<=k;j++) s[i][j]=mod(s[i][j-1]+d[i][j]);
	}
	if(m>=k){
		int num=0,fl=0;
		for(int i=1;i<=k;i++){
			cnt[a[i]]++;
			if(cnt[a[i]]==1) num++;
			else if(cnt[a[i]]==2) num--;
		}
		if(num==k) fl=1;
		for(int i=k+1;i<=m;i++){
			cnt[a[i]]++;
			if(cnt[a[i]]==1) num++;
			else if(cnt[a[i]]==2) num--;
			cnt[a[i-k]]--;
			if(cnt[a[i-k]]==1) num++;
			else if(cnt[a[i-k]]==0) num--;
			if(num==k) fl=1;
		}
		if(fl){
			printf("%lld\n",qpow(k,n-m)*(n-m+1)%cys);
			return 0;
		}
		int lf=k,rg=m-k+1;
		for(int i=1;i<=m;i++){
			if(vis[a[i]]){
				lf=i-1;
				break;
			}
			vis[a[i]]=1;
		}
		for(int i=1;i<=k;i++) vis[i]=0;
		for(int i=m;i>=1;i--){
			if(vis[a[i]]){
				rg=i+1;
				break;
			}
			vis[a[i]]=1;
		}
		ll ans=0;
		for(int i=1;i<=n-m+1;i++){
			ans=(ans+qpow(k,n-m)-(qpow(k,i-1)-d[i-1][lf])*(qpow(k,n-(i+m-1))-d[n-(i+m-1)][m-rg+1]))%cys;
			ans=mod(ans+cys);
		}
		printf("%lld\n",ans);
	}
	else{
		int lf=m,rg=1;
		for(int i=1;i<=m;i++){
			if(vis[a[i]]){
				lf=i-1;
				break;
			}
			vis[a[i]]=1;
		}
		for(int i=1;i<=k;i++) vis[i]=0;
		for(int i=m;i>=1;i--){
			if(vis[a[i]]){
				rg=i+1;
				break;
			}
			vis[a[i]]=1;
		}
		pw[0]=1;
		for(int i=1;i<=n;i++) pw[i]=pw[i-1]*k%cys;
		fac[0]=inv[0]=1;
		for(int i=1;i<=k;i++) fac[i]=fac[i-1]*i%cys;
		inv[k]=qpow(fac[k],cys-2);
		for(int i=k-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
		if(lf==m&&rg==1){
			ll ans=0;
			for(int i=1;i<=n-m+1;i++){
				for(int j=0;j<=min(k-m,n-(i+m-1));j++){
					ll tmp;
					if(m+j==k) tmp=pw[n-m-j];
					else if(j<n-(i+m-1)) tmp=(pw[n-m-j-1]*(m+j)-(pw[i-1]-d[i-1][m+j])*(pw[n-(i+m-1)-j-1]*(m+j)%cys-s[n-(i+m-1)-j-1][m+j]))%cys;
					else tmp=d[i-1][m+j];
					tmp=tmp*fac[k-m]%cys*inv[k-m-j]%cys;
					ans=(ans+cys+tmp)%cys;
//					cout<<"test "<<i<<' '<<j<<' '<<ans<<endl;
				}
			}
			printf("%lld\n",ans);
		}
		else{
			ll ans=0;
			for(int i=1;i<=n-m+1;i++){
				ans=(ans+qpow(k,n-m)-(qpow(k,i-1)-d[i-1][lf])*(qpow(k,n-(i+m-1))-d[n-(i+m-1)][m-rg+1]))%cys;
				ans=mod(ans+cys);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}