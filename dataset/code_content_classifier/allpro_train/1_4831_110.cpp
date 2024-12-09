#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define lint long long
using namespace std;
int q,m=1000000007;
lint x,y,f[99]={0,1,1};
int main(){
	scanf("%d",&q);
	rep(i,96)f[i+3]=f[i+1]+f[i+2];
	rep(i,q){
		scanf("%lld %lld",&x,&y);
		if(x>y)swap(x,y);
		if(y<=2){
			printf("1 %d ",y==1?1:x==1?2:4);
			continue;
		}
		rep(j,99){
			if(x<f[j]||y<f[j+1]){
				lint a=x==1?2:1;
				rep(k,j-2){
					lint n=f[j-1]+f[j-3-k]*f[k+2],m=f[j]+f[j-2-k]*f[k+2];
					if(n<=x&&m<=y)a+=(y-m)/n+1;
				}
				if(f[j]<=x){
					a++;
					rep(k,j-2)a+=(x-f[j])/(f[j-2-k]*f[k+2]);
				}
				printf("%d %d ",j-2,a%m);
				break;
			}
		}
	}
}