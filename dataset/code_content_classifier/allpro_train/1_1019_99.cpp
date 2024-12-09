#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int N=3010;
ll n,a[N],L;
const ld pi=acos(-1);
struct dot{ld x,y;}O,ans;
dot operator +(dot a,dot b){return (dot){a.x+b.x,a.y+b.y};}
dot operator -(dot a,dot b){return (dot){a.x-b.x,a.y-b.y};}
dot operator *(dot a,ld b){return (dot){a.x*b,a.y*b};}
dot ang(ld arc){
	return (dot){cos(arc),sin(arc)};
}
dot operator *(dot a,dot b){return (dot){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
int main(){
	cin>>n>>L;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		dot sum=O,B=ang(2*pi*a[i]/L);
		for (int j=i+1;j<=n;j++){
			dot M=O-ang(pi*(a[j]+a[i])/L);
			ans=ans+M*(j-i-1)+(B-M)*sum;
			sum=sum+ang(pi*(a[j]-a[i])/L);
		}
	}
	ans=ans*(6.0/n/(n-1)/(n-2));
	printf("%.15Lf %.15Lf\n",ans.x,ans.y);
}