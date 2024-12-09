#include<bits/stdc++.h>
using namespace std;
//#define int ll
#define ll long long
#define db double
#define rep(i,be,en) for(int i=be;i<=en;i++)
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
//const double pi=acos(-1);
const int mod=1e9+7;
const double eps = 1e-8;
using namespace std;
const int N=2e5+7;
const int M=1e6+7;

inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int T,n,m,fl,ans;


signed main(){
    T=read();
    while(T--){
    	n=read();
    	int l=read(),r=read(),s=read();
    	m=r-l+1;
    	if(s<m*(m+1)/2||s>(n-m+1+n)*m/2) puts("-1");
    	else{
    		int a[510]={0},b[510]={0},num=1,sum=0;
    		rep(i,l,r){
    			a[i]=num++;
    			sum+=a[i];
    			b[a[i]]=1;
			}
			int mx=n;
			for(int i=r;i>=l;i--){
				while(a[i]<mx&&sum<s){
					sum++;
					b[a[i]]=0;
					a[i]++;
					b[a[i]]=1;
				}
				mx--;
				if(sum==s) break;
			}
			int x=1;
			rep(i,1,n){
				if(a[i]==0){
					while(b[x]){
						x++;
					}
					a[i]=x;
					b[x]=1;
				}
				printf("%d ",a[i]);
			}
			puts("");
		}
	}
}

