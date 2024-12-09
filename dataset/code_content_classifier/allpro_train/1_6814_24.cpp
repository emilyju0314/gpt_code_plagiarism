#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int spe[100005];
int gv[100005];
ll F(int H,int W,int K){
	ll ans=0;
	int LIM=2*K+1500,top=0;
	For(i,0,H-1) gv[i]=gcd(W,i);
	For(k,1,H-1) if (gcd(k,W)>=1000) spe[++top]=k;
	For(k,W-W/2,W-1){
		//if (k%100==0) cerr<<k<<endl;
		int B=min(300000/(W-k),H-1),rp=(k*2==W?1:2);
		For(i,1,B){
			ll key1=1ll*i*(W-k)-gcd(k,i),key2=k;
			ll b1=max(0ll,(2*K+1-key1)/key2);
			if (b1>=i) ans-=rp;
			b1=min(b1,1ll*(H-1)); ans+=b1*rp; key1+=(++b1)*key2;
			for (;key1<=LIM&&b1<=H-1;key1+=key2,++b1){
				ll cv=key1-gv[abs(b1-i)]-gcd(W-k,b1);
				if (cv<=2*K-2&&b1!=i) ans+=rp;
			}
			ll arr=1ll*W*i;
			ll cv=arr-W-gcd(k,i)-gcd(W-k,i);
			if (cv<=2*K-2) ans+=rp;
			if (1ll*(W-k)*1000<=2*K+W+2000){
				Rep(p,top,1){
					int b=i-spe[p];
					if (b<b1||b>=H) continue;
					ll arr=1ll*(W-k)*i-gcd(k,i)+1ll*k*b;
					if (arr>2*K+W+1500) break;
					ll cv=arr-gv[abs(i-b)]-gcd(W-k,b);
					//if (i==2501&&spe[p]==2500) cerr<<cv<<' '<<arr<<endl;
					if (cv<=2*K-2&&arr>LIM) ans+=rp;//cerr<<cv<<' '<<arr<<endl;
				}
				For(p,1,top){
					int b=i+spe[p];
					if (b<b1||b>=H) continue;
					ll arr=1ll*(W-k)*i-gcd(k,i)+1ll*k*b;
					if (arr>2*K+W+1500) break;
					ll cv=arr-gv[abs(i-b)]-gcd(W-k,b);
					if (cv<=2*K-2&&arr>LIM) ans+=rp;
				}
			}
		}
	}
	return 2*ans;
}
/*
5000 5000 100000
197045732
100000 100000 100000
*/
int main(){
	int W,H,K;
	scanf("%d%d%d",&W,&H,&K);
	cout<<F(W,H,K)+F(H,W,K)<<endl;
	cerr<<clock()<<endl;
}